# 
# Usage: To re-create this platform project launch xsct with below options.
# xsct C:\Users\Christopher\Desktop\FinalProject\ENSC_452\AudioLabReal\FinalProject\platform.tcl
# 
# OR launch xsct and run below command.
# source C:\Users\Christopher\Desktop\FinalProject\ENSC_452\AudioLabReal\FinalProject\platform.tcl
# 
# To create the platform in a different location, modify the -out option of "platform create" command.
# -out option specifies the output directory of the platform project.

platform create -name {FinalProject}\
-hw {C:\Users\Christopher\Desktop\FinalProject\ENSC_452\audio_tutorial\FinalProject.xsa}\
-proc {ps7_cortexa9_0} -os {standalone} -fsbl-target {psu_cortexa53_0} -out {C:/Users/Christopher/Desktop/FinalProject/ENSC_452/AudioLabReal}

platform write
platform generate -domains 
platform active {FinalProject}
platform generate
platform active {FinalProject}
domain create -name {standalone_ps7_cortexa9_1} -display-name {standalone_ps7_cortexa9_1} -os {standalone} -proc {ps7_cortexa9_1} -runtime {cpp} -arch {32-bit} -support-app {empty_application}
platform generate -domains 
platform write
domain active {zynq_fsbl}
domain active {standalone_domain}
domain active {standalone_ps7_cortexa9_1}
platform generate -quick
platform generate -domains standalone_ps7_cortexa9_1 
platform active {FinalProject}
platform config -updatehw {C:/Users/Christopher/Desktop/FP/ENSC_452/hw_project/FinalProject.xsa}
platform generate -domains 
catch {platform remove design_1_wrapper}
domain create -name {testing} -os {standalone} -proc {ps7_cortexa9_0} -arch {32-bit} -display-name {testing} -desc {} -runtime {cpp}
platform generate -domains 
domain -report -json
platform write
domain remove testing
platform generate -domains 
platform write
bsp reload
bsp config extra_compiler_flags "-mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostartfiles -g -Wall -Wextra"
bsp config extra_compiler_flags "-mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostartfiles -g -Wall -Wextra -DUSE_AMP=1"
bsp write
bsp reload
catch {bsp regenerate}
platform generate -domains standalone_ps7_cortexa9_1 
platform generate
platform active {FinalProject}
domain active {zynq_fsbl}
bsp reload
domain active {standalone_domain}
bsp reload
bsp reload
domain active {standalone_ps7_cortexa9_1}
bsp reload
bsp config extra_compiler_flags "-mcpu=cortex-a9 -mfpu=vfpv3 -mfloat-abi=hard -nostartfiles -g -Wall -Wextra -DUSE_AMP=1"
bsp write
platform generate -domains 
platform generate
platform generate
platform generate
platform generate
platform generate
