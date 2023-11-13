package 源代码存储.Java.实验8.Code;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.Scanner;

public class CarSellManagement {
    
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Scanner sc2 = new Scanner(System.in);

        Car carTest=new Car("890","harmony","WA",202.0,"白色","20230928");
        //用以论证构造函数是正确的
        Save(carTest,"F:\\Study-Program\\源代码存储\\Java\\实验8\\Code\\test.txt");

        System.out.println("输入生产了几台汽车");
        int n=sc.nextInt();

        Car cars[]=new Car[n];

        for(int i=0;i<n;i++){
            cars[i]=produceCar(sc2);
            System.out.println(cars[i]);
            Save(cars[i],"F:\\Study-Program\\源代码存储\\Java\\实验8\\Code\\Car.txt");
        }

        sc.close();
        sc2.close();
    }
    //保存代码
    public static void Save(Car cr,String filename)
    {
        try {
            Writer writer = new FileWriter(filename, true);
            writer.write(cr + "\n");
            writer.flush();//刷新缓冲区，才能写入文件。
            writer.close();
        }
        catch (IOException e)
        {
            System.out.println("IO异常");
            e.printStackTrace();
        }
    }
    public static void sellCar(CarSell carsell, String filename) {
        try {
            Writer writer = new FileWriter(filename, true);
            writer.write(carsell + "\n");
            writer.flush();
            writer.close();
            System.out.println("汽车销售信息已写入" + filename + "文件");
        } catch (IOException e) {
            System.out.println("写入文件时出现IO异常");
            e.printStackTrace();
        }
    }
    public static void listCar(String filename) {
        Out(filename);
    }

    public static void Out(String filename) {
        try {
            Scanner scanner = new Scanner(new File(filename));
            while (scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println(filename + "文件不存在");
            e.printStackTrace();
        }
    }

    public static void listSelledCar(String filename) {
        Out(filename);
    }

    public static void deleteSelledCar(String filename, String carID) {
    try {
        File inputFile = new File(filename);
        File tempFile = new File("temp.txt");
        BufferedReader reader = new BufferedReader(new FileReader(inputFile));
        BufferedWriter writer = new BufferedWriter(new FileWriter(tempFile));
        String currentLine;
        while ((currentLine = reader.readLine()) != null) {
            if (currentLine.contains(carID)) {
                continue;
            }
            writer.write(currentLine + System.getProperty("line.separator"));
        }
        writer.close();
        reader.close();
        inputFile.delete();
        tempFile.renameTo(inputFile);
        System.out.println("删除成功");
    } catch (IOException e) {
        System.out.println("删除时发生IO异常");
        e.printStackTrace();
    }
}
    public static Car produceCar(Scanner sc)//汽车生产
    {
        
            Car cr=new Car();
            System.out.println("汽车编号");
            cr.setID(sc.nextLine());
            System.out.println("汽车品牌");
            cr.setModel(sc.nextLine());
            System.out.println("汽车型号");
            cr.setType(sc.nextLine());
            System.out.println("汽车价格");
            cr.setPrice(Double.parseDouble(sc.nextLine()));
            System.out.println("汽车颜色");
            cr.setColor(sc.nextLine());
            System.out.println("汽车生产日期");
            cr.setMFD(sc.nextLine());
            return cr;
    }
}
