package xyz.mlxkj.experiment4.model;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;

public class TimestampData {
    private LocalDateTime timestamp;

    // Getters and Setters
    public LocalDateTime getTimestamp() {
        return timestamp;
    }

    public void setTimestamp(LocalDateTime timestamp) {
        this.timestamp = timestamp;
    }

    public static TimestampData fromString(String input) throws DateTimeParseException {
        TimestampData timestampData = new TimestampData();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss.SSS");
        timestampData.setTimestamp(LocalDateTime.parse(input, formatter));

        return timestampData;
    }
}