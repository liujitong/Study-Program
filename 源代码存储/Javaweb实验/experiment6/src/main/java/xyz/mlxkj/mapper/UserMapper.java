package xyz.mlxkj.mapper;

import xyz.mlxkj.entity.User;

import java.util.List;

public interface UserMapper {
    User getUserById(int id);
    List<User> getAllUsers();
    void insertUser(User user);
    void updateUser(User user);
    void deleteUser(int id);
}