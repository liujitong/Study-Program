package 源代码存储.Java.实验8.Code;
public class Car {
    String ID;
    String model;
    String type;
    double price;
    String color;
    String MFD;

    public Car() {
    }

    public Car(String ID) {
        this.ID = ID;
    }

    public Car(String ID, String model, String type, double price, String color, String MFD) {
        this.ID = ID;
        this.model = model;
        this.type = type;
        this.price = price;
        this.color = color;
        this.MFD = MFD;
    }


    public String ID() {
        return ID;
    }

    public void setID(String ID) {
        this.ID = ID;
    }

    public String model() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String type() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public double price() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String color() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String MFD() {
        return MFD;
    }

    public void setMFD(String MFD) {
        this.MFD = MFD;
    }

    @Override
    public String toString() {
        return "Car{" +
                "汽车编号='" + ID + '\'' +
                ", 汽车品牌='" + model + '\'' +
                ", 汽车型号='" + type + '\'' +
                ", 汽车价格=" + price +
                ", 汽车颜色='" + color + '\'' +
                ", 汽车生产日期='" + MFD + '\'' +
                '}';
    }
}
