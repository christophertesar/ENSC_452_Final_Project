# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\Christopher\Desktop\ENSC_452\AudioLabReal\design_1_wrapper\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\Christopher\Desktop\ENSC_452\AudioLabReal\design_1_wrapper\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {design_1_wrapper}\
-hw {C:\Users\Christopher\Desktop\ENSC_452\audio_tutorial\design_1_wrapper.xsa}\
-fsbl-target {psu_cortexa53_0} -out {C:/Users/Christopher/Desktop/ENSC_452/AudioLabReal}

platform write
domain create -name {standalone_ps7_cortexa9_0} -display-name {standalone_ps7_cortexa9_0} -os {standalone} -proc {ps7_cortexa9_0} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform active {design_1_wrapper}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_0}
platform generate -quick
platform generate
platform generate
platform generate
platform generate
platform generate
platform active {design_1_wrapper}
platform generate -domains 
platform generate
