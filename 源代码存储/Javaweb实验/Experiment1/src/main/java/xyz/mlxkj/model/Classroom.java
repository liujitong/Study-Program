package xyz.mlxkj.model;

import java.util.List;

public class Classroom {
    private Long id;
    private String className;
    private List<Student> students; // 学生集合

    // Getters and Setters
    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getClassName() {
        return className;
    }

    public void setClassName(String className) {
        this.className = className;
    }

    public List<Student> getStudents() {
        return students;
    }

    public void setStudents(List<Student> students) {
        this.students = students;
    }

    @Override
    public String toString() {
        return "Classroom{" +
                "id=" + id +
                ", className='" + className + '\'' +
                ", students=" + students +
                '}';
    }
}