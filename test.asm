	BNE E     ; continue if not done 
	INY          ; increment index
	BNE $50     ; branch until page dont
	INC $11	; increment high byte of pointer
DDD:
E:
	LDA $11	; load page number as colour
	CPX $14      ; compare with max value
      
	BRK