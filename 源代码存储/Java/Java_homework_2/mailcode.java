package 源代码存储.Java.Java_homework_2;

public class mailcode {
    String mailcode;
    String std_code="[1-9]{1}[0-9]{5}";
    public void set_mailcode(String mailcode)
    {
        if(mailcode.matches(std_code)) this.mailcode=mailcode;
        else throw new IllegalArgumentException("邮编错误");
    }
}
