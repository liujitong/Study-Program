package xyz.mlxkj.experiment4.model;

public class User {
    private int id;
    private String name;
    private int age;

    // Getters and Setters
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public static User fromString(String input) {
        String[] parts = input.split(":");
        User user = new User();
        user.setId(Integer.parseInt(parts[0].split("=")[1]));
        user.setName(parts[1].split("=")[1]);
        user.setAge(Integer.parseInt(parts[2].split("=")[1]));

        return user;
    }
}