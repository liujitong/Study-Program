package xyz.mlxkj.experiment5;

import java.util.List;

public class Main {

    public static void main(String[] args) {
        UserDao userDao = new UserDao();

// 测试插入
        User newUser = new User();
        newUser.setName("John Doe");
        newUser.setEmail("john.doe@example.com");

        userDao.save(newUser);
        System.out.println("用户已插入: " + newUser);

// 测试更新
        newUser.setName("Jane Doe");
        userDao.update(newUser);
        System.out.println("用户已更新: " + newUser);

// 测试单个查询
        User foundUser = userDao.findById(newUser.getId());
        System.out.println("通过ID找到的用户: " + foundUser);

// 测试多个查询
        List<User> allUsers = userDao.findAll();
        System.out.println("所有用户: " + allUsers);

// 测试删除
        userDao.delete(foundUser);
        System.out.println("用户已删除: " + foundUser);

// 验证删除
        User deletedUser = userDao.findById(newUser.getId());
        if (deletedUser == null) {
            System.out.println("删除成功。用户不存在。");
        } else {
            System.out.println("删除失败。用户仍然存在: " + deletedUser);
        }
    }

}