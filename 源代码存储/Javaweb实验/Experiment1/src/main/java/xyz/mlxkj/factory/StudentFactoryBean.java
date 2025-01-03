package xyz.mlxkj.factory;

import org.springframework.beans.factory.FactoryBean;
import xyz.mlxkj.model.Student;

public class StudentFactoryBean implements FactoryBean<Student> {

    @Override
    public Student getObject() throws Exception {
        // Create and return a new Student object
        return new Student(4L, "Factory Bean Student", 23);
    }

    @Override
    public Class<?> getObjectType() {
        return Student.class;
    }

    @Override
    public boolean isSingleton() {
        return true;
    }

}