package xyz.mlxkj.factory;

import xyz.mlxkj.model.Student;

public class StudentFactory {
    public static Student createStudent(Long id, String name,Integer age) {
        return new Student(id, name,age);
    }
}
