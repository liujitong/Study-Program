package 源代码存储.Java.实验6.Code;
import java.util.ArrayList;
import java.util.Scanner;
public class Usertest
{
        public static void main(String[] args) {  
        ArrayList<User> users = new ArrayList<>();//创建ArrayList数组  
        Scanner scanner = new Scanner(System.in);  
        boolean exit = false;
        while (!exit) {
            //判断何时推出应用程序  
            System.out.println("请输入用户名（输入exit退出）:");  
            String username = scanner.nextLine();  
            if (username.equalsIgnoreCase("exit")) {  
                exit = true;  
                break;  
            }
            boolean usernameExists = false;  
            for (User user : users) {  
                if (user.get_Username().equals(username)) {  
                    usernameExists = true;  
                    break;  
                }  
            }  
            if (usernameExists) {  
                System.out.println("用户名已存在，请重新输入！");  
            } else
            {  
            //输入注册信息
            System.out.println("请输入密码（至少8位任意字符）:");  
            String password = scanner.nextLine();  
            System.out.println("请输入姓名（只能包含中文或英文字母）:");  
            String name = scanner.nextLine();  
            System.out.println("请输入身份证号码（18位数字，第一位和第七位是非0数字）:");  
            String idNumber = scanner.nextLine();  
            System.out.println("请输入年龄（大于等于0或小于150）:");  
            String age = scanner.nextLine();  
            System.out.println("请输入电话号码（可以是手机号码或座机号码）:");  
            String phoneNumber = scanner.nextLine();  
            System.out.println("请输入邮政编码（首位不能为0）:");  
            String postalCode = scanner.nextLine();  
            System.out.println("请输入邮箱地址（包含@符号，@符号前是单词字符，@符号后是域名形式的字符串）:");  
            String email = scanner.nextLine();  
            try {  
                User user = new User(username, password, name, idNumber, age, phoneNumber, postalCode, email);  
                users.add(user);  
                System.out.println("注册成功！");  
            } catch (IllegalArgumentException e) {  
                System.out.println("注册失败：" + e.getMessage());  
            }
            }  
        }  
        System.out.println("所有用户信息如下：");  
        for (User user : users) {  
            System.out.println(user);  
        }  
        scanner.close();
    }  
}

