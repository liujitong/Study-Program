package xyz.mlxkj.model;

import org.springframework.beans.factory.annotation.Autowired;

public class Student {
    private Long id;
    private String name;
    private Integer age;
    private Classroom classroom; // 关联班级

    // 构造方法
    public Student(Long id, String name) {
        this.id = id;
        this.name = name;
    }
    // 构造方法
    public Student(Long id, String name, Integer age) {
        this.id = id;
        this.name = name;
        this.age = age;
    }
    // 构造方法
    public Student(Long id, String name, Integer age, Classroom classroom) {
        this.id = id;
        this.name = name;
        this.age = age;
        this.classroom = classroom;
    }

    // Getters and Setters
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public Integer getAge() {
        return age;
    }

    public void setAge(Integer age) {
        this.age = age;
    }

    public Classroom getClassroom() {
        return classroom;
    }

    @Autowired(required = false) // 可选注入，避免在没有匹配的Bean时抛出异常
    public void setClassObj(Classroom classObj) {
        this.classroom = classObj; // 注意：这里应改为Classroom类型
    }

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", age=" + age +

                '}';
    }
}