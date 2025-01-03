package xyz.mlxkj.experiment3.controller;

import org.springframework.web.bind.annotation.*;
@RestController
@RequestMapping("/api")
public class ApiController {

    @GetMapping("/get")
    public String handleGet() {
        return "Handled GET request";
    }

    @PostMapping("/post")
    public String handlePost() {
        return "Handled POST request";
    }

    @DeleteMapping("/delete")
    public String handleDelete() {
        return "Handled DELETE request";
    }

    @PutMapping("/put")
    public String handlePut() {
        return "Handled PUT request";
    }
}