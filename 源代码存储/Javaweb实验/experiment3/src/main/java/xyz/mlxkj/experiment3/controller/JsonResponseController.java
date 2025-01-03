package xyz.mlxkj.experiment3.controller;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;

import java.util.HashMap;
import java.util.Map;

@RestController
@RequestMapping("/api")
public class JsonResponseController {

    @GetMapping("/json")
    public Map<String, Object> handleJsonRequest() {
        Map<String, Object> response = new HashMap<>();
        response.put("message", "Hello <example> 刘纪彤!");
        response.put("status", "success");
        response.put("data", new int[]{1, 2, 3, 4, 5});
        return response;
    }
}