	INY          ; increment index
	BNE $50     ; branch until page done
;   
;   
	INC $11	; increment high byte of pointer
	LDA $11	; load page number as colour
	CPX $11      ; compare with max value
	BNE $50     ; continue if not done 
      
	BRK          ; done - return to debugger