
# source the binary file
export PATH=$PATH:../jmvc/bin/


#!/bin/bash
#../jmvc/bin/H264AVCEncoderLibTestStaticd -vf test.cfg 1  
#../jmvc/bin/H264AVCEncoderLibTestStaticd -vf test.cfg 0  
#../jmvc/bin/H264AVCEncoderLibTestStaticd -vf testSingle.cfg 0  

# Evaluation operation
#H264AVCEncoderLibTestStaticd -vf 00evaluation.cfg 1  
#H264AVCEncoderLibTestStaticd -vf 00evaluation.cfg 0  

# Experiment operation
H264AVCEncoderLibTestStaticd -vf 00Exeperiment.cfg 1  
H264AVCEncoderLibTestStaticd -vf 00Exeperiment.cfg 0 
#MVCBitStreamAssemblerStaticd -vf assembler.cfg

