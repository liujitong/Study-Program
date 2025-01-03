package xyz.mlxkj.experiment3.controller;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
@Controller
public class MyController {

    @GetMapping("/up")
    public String showUpPage() {
        // 返回视图名，Thymeleaf会自动添加.html后缀
        return "up";
    }
}