package 源代码存储.Java.实验6.Code;

public class User
{
    //std__xx代表正则表达式规则的字符串。
    String Username;
    String std_user="[A-Za-z]{1}\\w*";
    String password;
    String std_psw=".{8,}";
    String name;
    String std_name="[A-za-z\u4e00-\u9fa5]+";
    String ID;
    String std_ID="[1-9]{1}[0-9]{5}[1-9]{1}[0-9]{10}[0-9X]{1}";
    String telephonenumber;
    String std_tele="(1[3-9]\\d{9})$|((\\d{3})[-.\\s]?\\d{8})$|((\\d{4})[-.\\s]?\\d{7})$";
    String mailcode;
    String std_code="[1-9]{1}[0-9]{5}";
    String email;
    String std_email="[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}";
    String age;
    String std_age="\\d|[1-9]\\d|[1-9][1-4]\\d|150";
    public User(String username, String password, String name, String idNumber, String age, String phoneNumber, String postalCode, String email)
    {
        //调用Set方法进行初始化。
        set_Username(username);  
        set_password(password);  
        set_name(name);  
        set_ID(idNumber);  
        set_age(age);  
        set_telephonenumber(phoneNumber);  
        set_mailcode(postalCode);  
        set_email(email); 
    }
    public void set_Username(String user)
    {
        if(user.matches(std_user)) Username=user;
        else throw new IllegalArgumentException("用户名输入错误");
    }
    public void set_password(String psw)
    {
        if(psw.matches(std_psw)) password=psw;
        else throw new IllegalArgumentException("密码与规定不匹配");
    }
    public void set_name(String name)
    {
        if(name.matches(std_name)) this.name=name;
        else throw new IllegalArgumentException("姓名与规定不匹配");
    }
    public void set_ID(String ID)
    {
       if(ID.matches(std_ID)) this.ID=ID;
        else throw new IllegalArgumentException("身份证信息与规定不匹配");
    }
    public void set_telephonenumber(String tele)
    {
        if(tele.matches(std_tele)) telephonenumber=tele;
        else throw new IllegalArgumentException("手机号不匹配");
    }
    public void set_mailcode(String mailcode)
    {
        if(mailcode.matches(std_code)) this.mailcode=mailcode;
        else throw new IllegalArgumentException("邮编错误");
    }
    public void set_email(String email)
    {
        if(email.matches(std_email)) this.email=email;
        else throw new IllegalArgumentException("电子邮件错误");
    }
    public void set_age(String age)
    {
        if(age.matches(std_age)) this.age=age;
        else throw new IllegalArgumentException("年龄错误");
    }
    public String get_Username()
    {
        return Username;
    }
    public String get_password()
    {
        return password;
    }
    public String get_name()
    {
        return name;
    }
    public String get_ID()
    {
        return ID;
    }
    public String get_telephonenumber()
    {
        return telephonenumber;
    }
    public String get_mailcode()
    {
        return mailcode;
    }
    public String get_email()
    {
        return email;
    }
    public String get_age()
    {
        return age;
    }
    public String toString()
    {
        return "个人信息:"+Username+"密码"+password+"身份证号"+ID+"姓名"+name+"年龄"+age+"邮编"+mailcode+"电子邮件"+email;
    }




}