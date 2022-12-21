function [ y ] = overlap_add( x,h,N )
%UNTITLED2 Summary of this function goes here
%   Detailed explanation goes here
    lx=length(x);
    M=length(h);
    if N<M
        N=M+1;
    end
    L=N+M-1;
    T=ceil(lx/N);
    t=zeros(1,M-1);
    x=[x,zeros(1,(T+1)*N-lx)];
    y=zeros(1,(T+1)*N);
    for i=0:1:T
        xi=i*N+1;
        x_seg=x(xi:xi+N-1);
        x1k=fft(x_seg,L);
        x2k=fft(h,L);
        yk=x1k.*x2k;
        y_seg=ifft(yk);
        y_seg(1:M-1)=y_seg(1:M-1)+t(1:M-1);
        t(1:M-1)=y_seg(N+1:L);
        y(xi:xi+N-1)=y_seg(1:N);
    end
    y=y(1:lx+M-1);
end

