package xyz.mlxkj.experiment6.test;

import xyz.mlxkj.experiment6.entity.User;
import xyz.mlxkj.experiment6.mapper.UserMapper;
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

        try (SqlSession session = sqlSessionFactory.openSession()) {
            UserMapper mapper = session.getMapper(UserMapper.class);

            // Insert a new user
            User newUser = new User();
            newUser.setName("John Doe");
            newUser.setAge(30);
            mapper.insertUser(newUser);
            session.commit();

            // Select all users
            List<User> users = mapper.getAllUsers();
            for (User user : users) {
                System.out.println(user.getId() + ", " + user.getName() + ", " + user.getAge());
            }

            // Update a user
            User updatedUser = users.get(0);
            updatedUser.setName("Jane Doe");
            mapper.updateUser(updatedUser);
            session.commit();

            // Delete a user
            mapper.deleteUser(users.get(0).getId());
            session.commit();
        }
    }
}