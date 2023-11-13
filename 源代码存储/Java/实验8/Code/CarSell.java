package 源代码存储.Java.实验8.Code;

public class CarSell {
    String SaleCode;
    String CarID;
    String buyerCode;
    public CarSell(){
    }
    public CarSell(String saleCode, String carID, String buyerCode) {
        SaleCode = saleCode;
        CarID = carID;
        this.buyerCode = buyerCode;
    }

    public String SaleCode() {
        return SaleCode;
    }

    public void setSaleCode(String saleCode) {
        SaleCode = saleCode;
    }

    public String CarID() {
        return CarID;
    }

    public void setCarID(String carID) {
        CarID = carID;
    }

    public String buyerCode() {
        return buyerCode;
    }

    public void setBuyerCode(String buyerCode) {
        this.buyerCode = buyerCode;
    }

    @Override
    public String toString() {
        return "CarSell{" +
                "订单编号='" + SaleCode + '\'' +
                ", 车辆编号='" + CarID + '\'' +
                ", 买家编号='" + buyerCode + '\'' +
                '}';
    }
}
