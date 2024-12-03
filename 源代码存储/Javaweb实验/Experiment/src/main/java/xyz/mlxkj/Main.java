package xyz.mlxkj;

import org.springframework.context.ApplicationContext;

import xyz.mlxkj.model.Classroom;
import xyz.mlxkj.model.Student;

public class Main {
    public static void main(String[] args) {

        //获取配置文件中的值
        ApplicationContext context = new org.springframework.context.support.ClassPathXmlApplicationContext("applicationContext.xml");
        Student student1 = (Student) context.getBean("student1");
        Student student2 = (Student) context.getBean("student2");
        Student student3 = (Student) context.getBean("student3");
        Student student4 = (Student) context.getBean("student4");
        Classroom classroom = (Classroom) context.getBean("classroom");
        Student studentAutoWire = (Student) context.getBean("studentAutoWire");

        System.out.println(student1);
        System.out.println(student2);
        System.out.println(student3);
        System.out.println(student4);
        System.out.println(classroom);
        System.out.println(studentAutoWire);

        System.out.println("Hello world!");
    }
}