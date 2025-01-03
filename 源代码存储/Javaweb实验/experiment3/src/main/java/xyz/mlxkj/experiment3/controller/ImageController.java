package xyz.mlxkj.experiment3.controller;


import org.springframework.core.io.ClassPathResource;
import org.springframework.core.io.Resource;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpStatus;
import org.springframework.http.MediaType;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;

import java.io.IOException;

@Controller
public class ImageController {

    @GetMapping("/image")
    public ResponseEntity<byte[]> handleImageRequest() throws IOException {
//        F:\Study-Program\源代码存储\Javaweb实验\experiment3\src\main\resources\image.jpg
        Resource resource = new ClassPathResource("image.jpg");//这里的路径是相对于resources的路径
        byte[] imageData = resource.getInputStream().readAllBytes();

        HttpHeaders headers = new HttpHeaders();
        headers.setContentType(MediaType.IMAGE_JPEG);
        headers.setContentLength(imageData.length);

        return new ResponseEntity<>(imageData, headers, HttpStatus.OK);
    }
}