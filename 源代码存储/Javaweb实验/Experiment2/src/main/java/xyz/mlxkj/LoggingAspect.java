package xyz.mlxkj;

import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;
import org.aspectj.lang.annotation.Before;
import org.springframework.stereotype.Component;

@Aspect
@Component
public class LoggingAspect {

    @Before("execution(* xyz.mlxkj.Student.*(..))")
    public void logBefore() {
        System.out.println("Before method execution.");
    }

    @After("execution(* xyz.mlxkj.Student.*(..))")
    public void logAfter() {
        System.out.println("After method execution.");
    }
}