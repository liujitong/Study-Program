package xyz.mlxkj.experiment3.controller;

import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.multipart.MultipartFile;

import javax.servlet.http.HttpServletRequest;
import java.util.Enumeration;

@RestController
@RequestMapping("/api")
public class PostRequestController {

    @PostMapping("/postHeadersAndBody")
    public ResponseEntity<String> handlePostRequest(
            HttpServletRequest request,
            @RequestHeader("Content-Type") String contentType,
            @RequestBody String body) {

        StringBuilder response = new StringBuilder("Content-Type: ").append(contentType).append("\n");
        response.append("Request Body: ").append(body).append("\n");

        Enumeration<String> headerNames = request.getHeaderNames();
        while (headerNames.hasMoreElements()) {
            String headerName = headerNames.nextElement();
            String headerValue = request.getHeader(headerName);
            response.append(headerName).append(": ").append(headerValue).append("\n");
        }

        return new ResponseEntity<>(response.toString(), HttpStatus.OK);
    }
}