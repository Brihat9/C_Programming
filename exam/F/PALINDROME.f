C     PROGRAM TO CHECK PALINDROME
      WRITE(*,*) 'ENTER ANY NUMBER'
      READ (*,1) N
1     FORMAT(I10)
      J=N
      L=0
      DO 10 I=1,100
      M=N/10
      K=N-M*10
      L=L*10+K
      N=N/10
10    CONTINUE
      WRITE(*,2) J,L
2     FORMAT(1X,'J= ',I10,3X,'L= ',I10)
      IF(J.EQ.L) THEN
        WRITE(*,*) 'PALINDROME'
      ELSE
        WRITE(*,*) 'NOT PALINDROME'
      ENDIF
      STOP
      END
