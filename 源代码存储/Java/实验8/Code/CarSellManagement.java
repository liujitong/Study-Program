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
        //这里设置两个scanner
        Scanner sc=new Scanner(System.in);
        Scanner sc2 = new Scanner(System.in);

        System.out.println("输入生产了几台汽车");
        int n=sc.nextInt();

        Car[] cars =new Car[n];
        //这里我要确保所有的数据都输入完了才可以进行，Scanner才释放掉
        for(int i=0;i<n;i++){
            cars[i]=produceCar(sc2);
            System.out.println(cars[i]);
            CarSave(cars[i],"F:\\Study-Program\\源代码存储\\Java\\实验8\\Code\\Car.txt");
        }
        //卖车
        System.out.println("有几个卖车记录");
        n=sc.nextInt();
        CarSell[] cs =new CarSell[n];
        for(int i=0;i<n;i++)
        {
            cs[i]=carsell(sc2);
            System.out.println(cs[i]);
            sellCarSave(cs[i], "F:\\Study-Program\\源代码存储\\Java\\实验8\\Code\\sell-car.txt");
        }
        //查看
        listCar("F:\\Study-Program\\源代码存储\\Java\\实验8\\Code\\Car.txt");
        listSelledCar("F:\\Study-Program\\源代码存储\\Java\\实验8\\Code\\sell-car.txt");


        //删除
        System.out.println("删除的ID");
        String de=sc2.nextLine();
        deleteSelledCar("F:\\Study-Program\\源代码存储\\Java\\实验8\\Code\\Car.txt", de);
        sc.close();
        sc2.close();
    }
    //保存代码
    public static void CarSave(Car cr,String filename)
    {
        try {
            Writer writer = new FileWriter(filename, true);//true为追加写入文件
            writer.write(cr + "\n");
            writer.flush();//刷新缓冲区，才能写入文件。
            writer.close();
            System.out.println("写入"+filename+"文件成功");
        }
        catch (IOException e)
        {
            System.out.println("IO异常");

        }
    }
    //销售记录保存
    public static void sellCarSave(CarSell carsell, String filename) {
        try {
            Writer writer = new FileWriter(filename, true);
            writer.write(carsell + "\n");
            writer.flush();
            writer.close();
            System.out.println("汽车销售信息已写入" + filename + "文件");
        } catch (IOException e) {
            System.out.println("写入文件时出现IO异常");

        }
    }
    //输出文件区
    public static void Out(String filename) {
        try {
            Scanner scanner = new Scanner(new File(filename));
            while (scanner.hasNextLine()) {
                System.out.println(scanner.nextLine());
            }
            scanner.close();
        } catch (FileNotFoundException e) {
            System.out.println(filename + "文件不存在");
        }
    }
    public static void listCar(String filename) {
        System.out.println("打印车辆信息");
        Out(filename);
    }
    public static void listSelledCar(String filename) {
        System.out.println("打印销售车辆信息");
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
        if(inputFile.delete()) System.out.println("输入文件删除成功");
        if(tempFile.renameTo(inputFile))System.out.println("重命名成功");
        System.out.println("删除成功");
    } catch (IOException e) {
        System.out.println("删除时发生IO异常");
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
            cr.setPrice(Double.parseDouble(sc.nextLine()));//这里可以做到自动去后两位
            System.out.println("汽车颜色");
            cr.setColor(sc.nextLine());
            System.out.println("汽车生产日期");
            cr.setMFD(sc.nextLine());
            return cr;
    }
    public static CarSell carsell (Scanner sc)
    {
        CarSell cs=new CarSell();
        System.out.println("订单编号");
        cs.setSaleCode(sc.nextLine());
        System.out.println("汽车编号");
        cs.setCarID(sc.nextLine());
        System.out.println("买家编号");
        cs.setBuyerCode(sc.nextLine());
        return cs;
    }
}
