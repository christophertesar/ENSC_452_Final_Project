# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\Christopher\Desktop\FP\ENSC_452\FP\Test_Project_2\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\Christopher\Desktop\FP\ENSC_452\FP\Test_Project_2\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {Test_Project_2}\
-hw {C:\Users\Christopher\Desktop\FP\ENSC_452\hw_project\FP_Hardware.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -fsbl-target {psu_cortexa53_0} -out {C:/Users/Christopher/Desktop/FP/ENSC_452/FP}

platform write
platform generate -domains 
platform active {Test_Project_2}
platform generate
platform config -remove-boot-bsp
platform write
platform config -create-boot-bsp
platform write
catch {platform remove TestProject}
platform generate
domain create -name {standalone_ps7_cortexa9_1} -display-name {standalone_ps7_cortexa9_1} -os {standalone} -proc {ps7_cortexa9_1} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform active {Test_Project_2}
domain active {standalone_domain}
domain active {zynq_fsbl}
domain active {standalone_ps7_cortexa9_1}
platform generate -quick
platform generate
platform generate -domains standalone_domain,standalone_ps7_cortexa9_1,zynq_fsbl 
platform active {Test_Project_2}
platform config -updatehw {C:/Users/Christopher/Desktop/FP/ENSC_452/hw_project/FP_Hardware.xsa}
platform generate -domains 
platform generate -domains standalone_ps7_cortexa9_1 
platform generate -domains standalone_ps7_cortexa9_1 
platform clean
platform generate
