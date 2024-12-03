package xyz.mlxkj.factory;

import xyz.mlxkj.model.Student;

public class StudentFactoryInstance
{
    public Student createStudentInstance(Long id, String name, int age) {
        return new Student(id, name, age);
    }
}
