package xyz.mlxkj.experiment4.controller;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;
import xyz.mlxkj.experiment4.model.TimestampData;
import xyz.mlxkj.experiment4.model.User;

import javax.servlet.http.HttpSession;
import java.time.format.DateTimeParseException;

@Controller
public class UserController {

    @GetMapping("/")
    public String index() {
        return "index";
    }

    @PostMapping("/submit")
    public String submit(
            @RequestParam String userData,
            @RequestParam String timestampData,
            HttpSession session,
            Model model) {
        try {
            User user = User.fromString(userData);
            TimestampData timestampDataObj = TimestampData.fromString(timestampData);

            session.setAttribute("user", user);
            session.setAttribute("timestampData", timestampDataObj);

            model.addAttribute("user", user);
            model.addAttribute("timestampData", timestampDataObj);
            return "redirect:/success";
        } catch (DateTimeParseException e) {
            model.addAttribute("error", "Invalid date format.");
            return "index";
        }
    }

    @GetMapping("/success")
    public String success(Model model, HttpSession session) {
        if (session.getAttribute("user") == null || session.getAttribute("timestampData") == null) {
            return "redirect:/login";
        }
        model.addAttribute("user", session.getAttribute("user"));
        model.addAttribute("timestampData", session.getAttribute("timestampData"));
        return "success";
    }

    @GetMapping("/login")
    public String login() {
        return "login";
    }
}