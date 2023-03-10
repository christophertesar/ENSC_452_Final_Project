# ZedBoard LED Constraints
#set_property PACKAGE_PIN T22 [get_ports {LEDs_out[0]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[0]}]
#set_property PACKAGE_PIN T21 [get_ports {LEDs_out[1]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[1]}]
#set_property PACKAGE_PIN U22 [get_ports {LEDs_out[2]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[2]}]
#set_property PACKAGE_PIN U21 [get_ports {LEDs_out[3]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[3]}]
#set_property PACKAGE_PIN V22 [get_ports {LEDs_out[4]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[4]}]
#set_property PACKAGE_PIN W22 [get_ports {LEDs_out[5]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[5]}]
#set_property PACKAGE_PIN U19 [get_ports {LEDs_out[6]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[6]}]
#set_property PACKAGE_PIN U14 [get_ports {LEDs_out[7]}]
#set_property IOSTANDARD LVCMOS33 [get_ports {LEDs_out[7]}]

# ZedBoard Audio Codec Constraints
set_property PACKAGE_PIN AA6 [get_ports BCLK]
set_property IOSTANDARD LVCMOS33 [get_ports BCLK]

set_property PACKAGE_PIN Y6 [get_ports LRCLK]
set_property IOSTANDARD LVCMOS33 [get_ports LRCLK]

set_property PACKAGE_PIN AA7 [get_ports SDATA_I]
set_property IOSTANDARD LVCMOS33 [get_ports SDATA_I]

set_property PACKAGE_PIN Y8 [get_ports SDATA_O]
set_property IOSTANDARD LVCMOS33 [get_ports SDATA_O]

#MCLK
set_property PACKAGE_PIN AB2 [get_ports FCLK_CLK1]
set_property IOSTANDARD LVCMOS33 [get_ports FCLK_CLK1]

set_property PACKAGE_PIN AB4 [get_ports IIC_0_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports IIC_0_scl_io]

set_property PACKAGE_PIN AB5 [get_ports IIC_0_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports IIC_0_sda_io]

set_property PACKAGE_PIN AB1 [get_ports {GPIO_0_tri_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_0_tri_io[0]}]

set_property PACKAGE_PIN Y5 [get_ports {GPIO_0_tri_io[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_0_tri_io[1]}]



set_property PACKAGE_PIN Y21  [get_ports {VGA_B[0]}];  # "VGA-B1"
set_property IOSTANDARD LVCMOS33  [get_ports {VGA_B[0]}];  # "VGA-B1"

set_property PACKAGE_PIN Y20  [get_ports {VGA_B[1]}];  # "VGA-B2"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_B[1]}];  # "VGA-B3"

set_property PACKAGE_PIN AB20 [get_ports {VGA_B[2]}];  # "VGA-B3"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_B[2]}];  # "VGA-B3"

set_property PACKAGE_PIN AB19 [get_ports {VGA_B[3]}];  # "VGA-B4"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_B[3]}];  # "VGA-B4"

set_property PACKAGE_PIN AB22 [get_ports {VGA_G[0]}];  # "VGA-G1"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_G[0]}];  # "VGA-G1"

set_property PACKAGE_PIN AA22 [get_ports {VGA_G[1]}];  # "VGA-G2"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_G[1]}];  # "VGA-G3"

set_property PACKAGE_PIN AB21 [get_ports {VGA_G[2]}];  # "VGA-G3"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_G[2]}];  # "VGA-G4"

set_property PACKAGE_PIN AA21 [get_ports {VGA_G[3]}];  # "VGA-G4"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_G[3]}];  # "VGA-HS"

set_property PACKAGE_PIN AA19 [get_ports {VGA_HS}];  # "VGA-HS"
set_property IOSTANDARD LVCMOS33 [get_ports {VGA_HS}];  # "VGA-HS"

set_property PACKAGE_PIN V20  [get_ports {VGA_R[0]}];  # "VGA-R1"
set_property IOSTANDARD LVCMOS33  [get_ports {VGA_R[0]}];  # "VGA-R1"

set_property PACKAGE_PIN U20  [get_ports {VGA_R[1]}];  # "VGA-R2"
set_property IOSTANDARD LVCMOS33  [get_ports {VGA_R[1]}];  # "VGA-R2"

set_property PACKAGE_PIN V19  [get_ports {VGA_R[2]}];  # "VGA-R3"
set_property IOSTANDARD LVCMOS33  [get_ports {VGA_R[2]}];  # "VGA-R3"

set_property PACKAGE_PIN V18  [get_ports {VGA_R[3]}];  # "VGA-R4"
set_property IOSTANDARD LVCMOS33  [get_ports {VGA_R[3]}];  # "VGA-R4"

set_property PACKAGE_PIN Y19  [get_ports {VGA_VS}];  # "VGA-VS"
set_property IOSTANDARD LVCMOS33  [get_ports {VGA_VS}];  # "VGA-VS"
