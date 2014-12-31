C       PROGRAM TO FIND PALINDROME
        WRITE(*,*) 'ENTER ANY NEMBER'
        READ(*,1) I
1       FORMAT(I10)
        J=I
        L=0
2       IF(I.GT.0) THEN
        K=I-I/10*10
        L=L*10+K
        I=I/10
        GOTO 2
        ENDIF
        IF(J.EQ.L) THEN
            WRITE(*,*) 'PALINDROME'
        ELSE
            WRITE(*,*) 'NOT PALINDROME'
        ENDIF
        STOP
        END
