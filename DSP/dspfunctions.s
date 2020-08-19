.global _MotorDSP_Init
.global _ACCA_SetValue
.global _ACCB_SetValue
    
    _MotorDSP_Init:
	MOV #0x10C0,W3
	MOV W3,CORCON
	RETURN
	
    _ACCA_SetValue:
	CLR A
	LAC W0,A
	RETURN
    
    _ACCB_SetValue:
	CLR B
	LAC W0,B
	RETURN
	
	.end
    


