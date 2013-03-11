
# source the binary file
export PATH=$PATH:../../JMVC/jmvc/bin/


#!/bin/bash
#../jmvc/bin/H264AVCEncoderLibTestStaticd -vf test.cfg 1  
#../jmvc/bin/H264AVCEncoderLibTestStaticd -vf test.cfg 0  
#../jmvc/bin/H264AVCEncoderLibTestStaticd -vf testSingle.cfg 0  

# Evaluation operation
#H264AVCEncoderLibTestStaticd -vf 00evaluation.cfg 1  
#H264AVCEncoderLibTestStaticd -vf 00evaluation.cfg 0  

# Experiment operation Ex01
#H264AVCEncoderLibTestStaticd -vf 00Exeperiment.cfg 1  
#H264AVCEncoderLibTestStaticd -vf 00Exeperiment.cfg 0 
#MVCBitStreamAssemblerStaticd -vf assembler.cfg

# Experiment operation Ex02
#H264AVCEncoderLibTestStaticd -vf 00Ex2Experiment.cfg 0  
#H264AVCEncoderLibTestStaticd -vf 00Ex2Experiment.cfg 1 


export PATH=$PATH:../../JM/bin/
lencod.exe -f encoder_stereo.cfg 
#lencod.exe -f 00Ex2ExperimentIdt.cfg
