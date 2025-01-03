package xyz.mlxkj.experiment6.test;

import xyz.mlxkj.entity.User;
import xyz.mlxkj.mapper.UserMapper;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import java.io.IOException;
import java.io.Reader;
import java.util.List;

public class TestMyBatis {
    public static void main(String[] args) throws IOException {
        String resource = "mybatis-config.xml";
        Reader reader = Resources.getResourceAsReader(resource);
        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(reader);

        SqlSession session = null;
        try {
            session = sqlSessionFactory.openSession();
            UserMapper mapper = session.getMapper(UserMapper.class);

            // Insert a new user
            System.out.println("插入新用户");
            User newUser = new User();
            newUser.setName("John Doe");
            newUser.setAge(30);
            mapper.insertUser(newUser);
            session.commit();

            // Select all users
            System.out.println("查询所有用户");
            List<User> users = mapper.getAllUsers();
            for (User user : users) {
                System.out.println(user.getId() + ", " + user.getName() + ", " + user.getAge());
            }

            // Update a user
            System.out.println("更新用户");
            User updatedUser = users.get(0);
            updatedUser.setName("Jane Doe Update");
            mapper.updateUser(updatedUser);
            session.commit();
            users = mapper.getAllUsers();
            for(User user:users){
               System.out.println(user.getId() + ", " + user.getName() + ", " + user.getAge());
              }

            // Delete a user
            System.out.println("删除用户");
            mapper.deleteUser(users.get(0).getId());
            session.commit();
            users = mapper.getAllUsers();
            for(User user:users){
                System.out.println(user.getId() + ", " + user.getName() + ", " + user.getAge());
            }


        } finally {
            if (session != null) {
                session.close();
            }
        }
    }
}