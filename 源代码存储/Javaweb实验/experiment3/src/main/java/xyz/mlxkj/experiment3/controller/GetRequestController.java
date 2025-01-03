package xyz.mlxkj.experiment3.controller;

import  org.springframework.web.bind.annotation.GetMapping;
import  org.springframework.web.bind.annotation.RequestHeader;
import  org.springframework.web.bind.annotation.RequestParam;
import  org.springframework.web.bind.annotation.RestController;
import org.springframework.web.bind.annotation.RequestMapping;
import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import java.util.Enumeration;

@RestController
@RequestMapping("/api")
public class GetRequestController {

    @GetMapping("/getHeadersAndCookies")
    public String handleGetRequest(
            HttpServletRequest request,
            @RequestHeader("User-Agent") String userAgent,
            @RequestParam(value = "param1", required = false) String param1) {

        StringBuilder response = new StringBuilder("User-Agent: ").append(userAgent).append("\n");
        response.append("Request Parameters:\n");
        Enumeration<String> parameterNames = request.getParameterNames();
        while (parameterNames.hasMoreElements()) {
            String paramName = parameterNames.nextElement();
            String[] paramValues = request.getParameterValues(paramName);
            response.append(paramName).append(": ").append(String.join(", ", paramValues)).append("\n");
        }

        response.append("Cookies:\n");
        Cookie[] cookies = request.getCookies();
        if (cookies != null) {
            for (Cookie cookie : cookies) {
                response.append(cookie.getName()).append(": ").append(cookie.getValue()).append("\n");
            }
        }

        return response.toString();
    }
}