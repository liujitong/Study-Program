import javafx.animation.KeyFrame;
import javafx.animation.Timeline;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.util.Duration;
import javafx.util.Pair;
import jdk.nashorn.internal.runtime.regexp.joni.exception.ValueException;
import tableElements.*;

import javax.swing.*;
import javax.swing.text.Style;
import java.io.*;
import java.net.URL;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;
import java.util.ResourceBundle;

public class MainSceneController implements Initializable {

    private final int SAMPLE_COUNT = 7;
    private final String[] RS_NAME = {"ADD", "MULT", "LOAD", "STORE"};
    private final String[] OP_NAME = {"ADD", "SUB", "MUL", "DIV", "LD", "ST"};
    private final int[] CONTINUE_STEPS = {5, 10, 15, 20};

    public Label clockLabel;
    public Label clockTimeLabel;
    public TableView<RSRow> rsTableView;
    public TableView<CodeRow> codeTableView;
    public TableView<FPRegRow> fpRegTableView;
    public TableView<CPURegRow> cpuRegTableView;
    public TableView<MemRow> memTableView;
    public Menu changeMenu;
    public TableView<LsQueueRow> lsQueueTableView;
    public Label hintTextLabel;

    private int currentTime;
    private boolean timerRunning;

    @FXML
    private Button inputButton;

    @FXML
    private MenuButton sampleButton;

    @FXML
    private Button startButton;

    @FXML
    private Button stepButton;

    @FXML
    private MenuButton continueButton;

    @FXML
    private Button tailButton;

    private Pipeline pipeline;

    @FXML
    void inputClicked(ActionEvent event) {
        String inputCode = "";
        while (true) {
            // Create the custom dialog.
            Dialog<String> dialog = new Dialog<>();
            dialog.setTitle("????????????");

            // Set the button types.
            ButtonType loginButtonType = new ButtonType("??????", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, ButtonType.CANCEL);

            TextArea tArea = new TextArea(inputCode);
            tArea.setPromptText("????????????????????????");
            BorderPane borderPane = new BorderPane(tArea);
            BorderPane.setMargin(borderPane, new Insets(20, 20, 20, 20));

            dialog.getDialogPane().setContent(borderPane);

            // Convert the result to a username-password-pair when the login button is clicked.
            dialog.setResultConverter(dialogButton -> {
                if (dialogButton == loginButtonType) {
                    return tArea.getText();
                }
                return null;
            });

            Optional<String> result = dialog.showAndWait();

            if (result.isPresent()) {
                inputCode = result.get();
                if (inputCode(inputCode)) {
                    refreshCodeSection();
                    break;
                }
            } else {
                return;
            }
        }
    }

    private boolean inputCode(String code) {
        String[] codeLines = code.split("\\r?\\n");
        // Cache current pipeline code
        ArrayList<String> cachedList = new ArrayList<>(pipeline.cmdList.size());
        cachedList.addAll(pipeline.cmdList);
        pipeline.cmdList.clear();
        for (String line : codeLines) {
            line = line.trim();
            if (line.startsWith("#") || line.startsWith("//")) {
                continue;
            }
            if (line.matches(".*\\w.*")) {
                System.out.println(line);
                pipeline.addCmd(line);
            }
        }
        int parseResult = pipeline.parser();
        if (parseResult == -1) {
            showAlert(Alert.AlertType.ERROR, "??????", "????????????", pipeline.parseErrMessage);
            pipeline.cmdList.clear();
            pipeline.cmdList.addAll(cachedList);
            pipeline.parser();
            return false;
        } else {
            return true;
        }
    }

    @FXML
    void startClicked(ActionEvent event) {
        if (pipeline.isRunning) {
            pipeline.clean();
            pipeline.isRunning = false;
            currentTime = 0;
            switchStatus(false);
            refreshAll();
        } else {
            if (pipeline.decodedList.size() == 0) {
                showAlert(Alert.AlertType.ERROR, "??????", "????????????",
                        "???????????????????????????????????????????????????????????????????????????????????????");
                return;
            }
            currentTime = 0;
            pipeline.run();
            switchStatus(true);
            refreshAll();
        }
    }

    private void continueClicked(int step) {
        if (allFinished()) return;
        for (int i = 0; i < step; ++ i) {
            pipeline.nextStep();
            currentTime += 1;
            if (allFinished()) {
                stepButton.setDisable(true);
                continueButton.setDisable(true);
                tailButton.setDisable(true);
                hintTextLabel.setText("????????????????????????");
                break;
            }
        }
        refreshAll();
    }

    @FXML
    void stepClicked(ActionEvent event) {
        if (allFinished()) return;
        pipeline.nextStep();
        currentTime += 1;
        refreshAll();
        if (allFinished()) {
            stepButton.setDisable(true);
            continueButton.setDisable(true);
            tailButton.setDisable(true);
            hintTextLabel.setText("????????????????????????");
        }
    }

    @FXML
    void tailClicked(ActionEvent event) {
        if (timerRunning) {
            tailButton.setGraphic(new ImageView("/resources/tail.png"));
            tailButton.setText("????????????");
            stepButton.setDisable(false);
            continueButton.setDisable(false);
            timerRunning = false;
        } else {
            tailButton.setGraphic(new ImageView("/resources/pause.png"));
            tailButton.setText("????????????");
            stepButton.setDisable(true);
            continueButton.setDisable(true);
            timerRunning = true;
        }
    }

    private void backgroundSchedulePlay() {
        if (!timerRunning) return;
        stepClicked(null);
    }

    @Override
    public void initialize(URL location, ResourceBundle resources) {
        inputButton.setGraphic(new ImageView("/resources/input.png"));
        sampleButton.setGraphic(new ImageView("/resources/sample.png"));
        startButton.setGraphic(new ImageView("/resources/simulate.png"));
        stepButton.setGraphic(new ImageView("/resources/step.png"));
        continueButton.setGraphic(new ImageView("/resources/continue.png"));
        tailButton.setGraphic(new ImageView("/resources/tail.png"));

        clockLabel.setGraphic(new ImageView("/resources/time.png"));
        memTableView.setPlaceholder(new Label("????????????????????????0"));
        codeTableView.setPlaceholder(new Label("?????????????????????????????????????????????????????????????????????????????????"));
        lsQueueTableView.setPlaceholder(new Label("?????????????????????????????????Load-Store??????????????????Busy??????"));

        switchStatus(false);

        pipeline = new Pipeline();

        refreshAll();

        for (int i = 0; i < SAMPLE_COUNT; ++ i) {
            MenuItem sampleItem = new MenuItem("??????" + String.valueOf(i + 1));
            int finalI = i;
            sampleItem.setOnAction(new EventHandler<ActionEvent>() {
                @Override
                public void handle(ActionEvent event) {
                    InputStream in = getClass().getResourceAsStream(String.format("/samples/s%d.txt", finalI + 1));
                    BufferedReader reader = new BufferedReader(new InputStreamReader(in));
                    try {
                        String line = reader.readLine();
                        StringBuilder sb = new StringBuilder();
                        while (line != null) {
                            sb.append(line).append("\n");
                            line = reader.readLine();
                        }
                        if (inputCode(sb.toString())) {
                            // TODO: Deduplicate this code.
                            refreshCodeSection();
                        }
                    } catch (IOException e) {
                        showAlert(Alert.AlertType.ERROR, "??????", "????????????", "???????????????????????????????????????");
                    }
                }
            });
            sampleButton.getItems().add(sampleItem);
        }
        for (int cs : CONTINUE_STEPS) {
            MenuItem contItem = new MenuItem(String.format("??????%d???", cs));
            contItem.setOnAction(event -> continueClicked(cs));
            continueButton.getItems().add(contItem);
        }
        timerRunning = false;
        Timeline backgroundTask = new Timeline(new KeyFrame(Duration.seconds(1),
                event -> backgroundSchedulePlay()));
        backgroundTask.setCycleCount(Timeline.INDEFINITE);
        backgroundTask.play();
    }

    private void setClockTime(int time) {
        clockTimeLabel.setText(String.valueOf(time));
    }

    private void switchStatus(boolean isRunning) {
        if (isRunning) {
            inputButton.setDisable(true);
            sampleButton.setDisable(true);
            startButton.setText("????????????");
            stepButton.setDisable(false);
            continueButton.setDisable(false);
            tailButton.setDisable(false);
            changeMenu.setDisable(true);
        } else {
            inputButton.setDisable(false);
            sampleButton.setDisable(false);
            startButton.setText("????????????");
            setClockTime(0);
            stepButton.setDisable(true);
            continueButton.setDisable(true);
            tailButton.setDisable(true);
            fpRegTableView.setEditable(true);
            changeMenu.setDisable(false);
            tailButton.setGraphic(new ImageView("/resources/tail.png"));
            tailButton.setText("????????????");
            hintTextLabel.setText("????????????");
            timerRunning = false;
        }
    }

    private void refreshAll() {
        refreshReservationStation();
        refreshCodeSection();
        refreshRegisters();
        refreshMemory();
        refreshLsQueue();
        setClockTime(currentTime);
    }

    private void refreshReservationStation() {
        ObservableList<RSRow> a = FXCollections.observableArrayList();
        for (int i = 0; i < 2; ++ i) {
            for (int j = 0; j < 3; ++ j) {
                if (i == 1 && j == 2) continue;
                String rsName = RS_NAME[i] + String.valueOf(j + 1);
                RSRow rRow = new RSRow(rsName);
                TMLBuffer thisBuffer = pipeline.buffers[i][j];
                if (thisBuffer.busy) {
                    rRow.setBusy("Yes");
                    int op = thisBuffer.operator;
                    rRow.setOp(OP_NAME[i * 2 + op]);
                    if (thisBuffer.rsIndex[0][0] != -1) {
                        rRow.setQj(RS_NAME[thisBuffer.rsIndex[0][0]] +
                                String.valueOf(thisBuffer.rsIndex[0][1] + 1));
                    } else {
                        rRow.setVj(String.valueOf(thisBuffer.value[0]));
                    }
                    if (thisBuffer.rsIndex[1][0] != -1) {
                        rRow.setQk(RS_NAME[thisBuffer.rsIndex[1][0]] +
                                String.valueOf(thisBuffer.rsIndex[1][1] + 1));
                    } else {
                        rRow.setVk(String.valueOf(thisBuffer.value[1]));
                    }
                } else {
                    rRow.setBusy("No");
                }
                a.add(rRow);
            }
        }
        rsTableView.getItems().setAll(a);
    }

    private void refreshCodeSection() {
        ObservableList<CodeRow> a = FXCollections.observableArrayList();
        for (Cmd cmd : pipeline.decodedList) {
            CodeRow cRow = new CodeRow(a.size() + 1, cmd.text);
            if (cmd.state >= 1) cRow.setSt1("OK");
            if (cmd.state >= 2) cRow.setSt2("OK");
            if (cmd.state >= 3) cRow.setSt3("OK");
            a.add(cRow);
        }
        codeTableView.getItems().setAll(a);
    }

    private void refreshRegisters() {
        ObservableList<CPURegRow> a = FXCollections.observableArrayList();
        for (int i = 0; i < 8; ++ i) {
            CPURegRow cRow = new CPURegRow("R" + String.valueOf(i));
            cRow.setValue(String.valueOf(pipeline.cpuRegisters[i]));
            a.add(cRow);
        }
        cpuRegTableView.getItems().setAll(a);
        ObservableList<FPRegRow> b = FXCollections.observableArrayList();
        for (int i = 0; i <= 30; i += 2) {
            FPRegRow fRow = new FPRegRow("F" + String.valueOf(i));
            fRow.setValue(String.valueOf(pipeline.fpRegisters[i]));
            String rsName;
            if (pipeline.fpRegistersStatus[i][0] == -1) {
                // if Qi is empty
                rsName = "";
            } else {
                // if this register is going to be filled by an RS, show it.
                rsName = RS_NAME[pipeline.fpRegistersStatus[i][0]] +
                        String.valueOf(pipeline.fpRegistersStatus[i][1] + 1);
            }
            fRow.setRs(rsName);
            b.add(fRow);
        }
        fpRegTableView.getItems().setAll(b);
    }

    private void refreshMemory() {
        ObservableList<MemRow> a = FXCollections.observableArrayList();
        for (int i = 0; i < 4096; ++ i) {
            if (pipeline.memory[i] != 0.0) {
                MemRow memRow = new MemRow();
                memRow.setOffset(String.valueOf(i));
                memRow.setValue(String.valueOf(pipeline.memory[i]));
                a.add(memRow);
            }
        }
        memTableView.getItems().setAll(a);
    }

    private void refreshLsQueue() {
        ObservableList<LsQueueRow> a = FXCollections.observableArrayList();
        int id = 1;
        for (Integer queueId : pipeline.loadStoreQueue) {
            LsQueueRow lsQueueRow = new LsQueueRow();
            lsQueueRow.setId(String.valueOf(id));
            int rsId = queueId / 3;
            int inId = queueId % 3;
            TMLBuffer thisBuffer = pipeline.buffers[rsId + 2][inId];
            if (!thisBuffer.busy) {
                showAlert(Alert.AlertType.INFORMATION, "??????", "????????????",
                        "?????????LS???????????????????????????????????????busy");
            }
            lsQueueRow.setOp(OP_NAME[rsId + 4]);
            lsQueueRow.setRsName(RS_NAME[rsId + 2] + String.valueOf(inId + 1));
            if (rsId == 1) {
                // Only store need to know qj and vj
                if (thisBuffer.rsIndex[0][0] != -1) {
                    lsQueueRow.setQj(RS_NAME[thisBuffer.rsIndex[0][0]] +
                            String.valueOf(thisBuffer.rsIndex[0][1] + 1));
                } else {
                    lsQueueRow.setVj(String.valueOf(thisBuffer.value[0]));
                }
            }
            lsQueueRow.setAddress(String.valueOf(thisBuffer.address));
            a.add(lsQueueRow);
            id += 1;
        }
        lsQueueTableView.getItems().setAll(a);
    }

    private void showAlert(Alert.AlertType type, String title, String header, String content) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setHeaderText(header);
        alert.setContentText(content);
        alert.showAndWait();
    }

    public void exitClicked(ActionEvent actionEvent) {
        System.exit(0);
    }

    public void aboutClicked(ActionEvent actionEvent) {
        showAlert(Alert.AlertType.INFORMATION, "??????", "???????????????",
                "????????????????????????????????????????????????????????????????????????Tomasulo??????????????????");
    }

    public void registerChangeClicked(ActionEvent actionEvent) {
        Dialog<Pair<String, String>> dialog = new Dialog<>();
        dialog.setTitle("???????????????");
        dialog.setHeaderText("??????????????????????????????????????????R????????????CPU?????????????????????F???????????????????????????\n" +
                "???????????????????????????F0, F2, ..., F30???CPU?????????????????????R0, R1, ..., R7");

        // Set the button types.
        ButtonType loginButtonType = new ButtonType("??????", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, ButtonType.CANCEL);

        GridPane gridPane = new GridPane();
        TextField regTextField = new TextField();
        regTextField.setPromptText("????????????");
        Label equalLabel = new Label("=");
        TextField regValueField = new TextField();
        regValueField.setPromptText("????????????");
        gridPane.add(regTextField, 0, 0);
        gridPane.add(equalLabel, 1, 0);
        gridPane.add(regValueField, 2, 0);
        gridPane.setAlignment(Pos.CENTER);
        GridPane.setMargin(equalLabel, new Insets(0, 20, 0, 20));

        dialog.getDialogPane().setContent(gridPane);

        // Convert the result to a username-password-pair when the login button is clicked.
        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                return new Pair<>(regTextField.getText(), regValueField.getText());
            }
            return null;
        });

        Optional<Pair<String, String>> result = dialog.showAndWait();

        if (result.isPresent()) {
            try {
                Pair<String, String> res = result.get();
                String reg = res.getKey().trim();
                String val = res.getValue().trim();
                if (reg.startsWith("R")) {
                    int id = Integer.valueOf(reg.substring(1));
                    int v = Integer.valueOf(val);
                    if (id >= 0 && id <= 7) {
                        pipeline.cpuRegisters[id] = v;
                    } else {
                        throw new ValueException("???????????????");
                    }
                } else if (reg.startsWith("F")) {
                    int id = Integer.valueOf(reg.substring(1));
                    float v = Float.valueOf(val);
                    if (id >= 0 && id <= 30 && id % 2 == 0) {
                        pipeline.fpRegisters[id] = v;
                    } else {
                        throw new ValueException("???????????????");
                    }
                } else {
                    throw new ValueException("??????????????????");
                }
            } catch (Exception e) {
                showAlert(Alert.AlertType.ERROR, "??????", "????????????", "???????????????????????????\n" +
                        e.getMessage() + "\n???????????????????????????????????????");
            }
            refreshRegisters();
        }
    }

    public void memoryChangeClicked(ActionEvent actionEvent) {
        Dialog<Pair<String, String>> dialog = new Dialog<>();
        dialog.setTitle("????????????");
        dialog.setHeaderText("?????????????????????0-4095?????????????????????????????????????????????");

        // Set the button types.
        ButtonType loginButtonType = new ButtonType("??????", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().addAll(loginButtonType, ButtonType.CANCEL);

        GridPane gridPane = new GridPane();
        TextField regTextField = new TextField();
        regTextField.setPromptText("????????????");
        Label equalLabel = new Label("=");
        TextField regValueField = new TextField();
        regValueField.setPromptText("???");
        gridPane.add(regTextField, 0, 0);
        gridPane.add(equalLabel, 1, 0);
        gridPane.add(regValueField, 2, 0);
        gridPane.setAlignment(Pos.CENTER);
        GridPane.setMargin(equalLabel, new Insets(0, 20, 0, 20));

        dialog.getDialogPane().setContent(gridPane);

        // Convert the result to a username-password-pair when the login button is clicked.
        dialog.setResultConverter(dialogButton -> {
            if (dialogButton == loginButtonType) {
                return new Pair<>(regTextField.getText(), regValueField.getText());
            }
            return null;
        });

        Optional<Pair<String, String>> result = dialog.showAndWait();

        if (result.isPresent()) {
            try {
                Pair<String, String> res = result.get();
                String reg = res.getKey().trim();
                String val = res.getValue().trim();
                int offset = Integer.valueOf(reg);
                if (offset < 0 || offset > 4095) {
                    throw new ValueException("????????????");
                }
                float v = Float.valueOf(val);
                pipeline.memory[offset] = v;
            } catch (Exception e) {
                showAlert(Alert.AlertType.ERROR, "??????", "????????????", "???????????????????????????\n" +
                        e.getMessage() + "\n???????????????????????????????????????");
            }
            refreshMemory();
        }
    }

    private boolean allFinished() {
        for (Cmd cmd : pipeline.decodedList) {
            if (cmd.state != 3) return false;
        }
        return true;
    }
}
