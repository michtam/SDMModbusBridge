const int sdm_registers[] = {
  // source https://github.com/reaper7/SDM_Energy_Meter/blob/master/SDM.h
  //ADDR     REGISTER NAME                                UNIT          | SDM630  | SDM230  | SDM220  | SDM120CT| SDM120  | SDM72D  |
  0x0000, // SDM_PHASE_1_VOLTAGE                          [V]           |    1    |    1    |    1    |    1    |    1    |         |
  0x0002, // SDM_PHASE_2_VOLTAGE                          [V]           |    1    |         |         |         |         |         |
  0x0004, // SDM_PHASE_3_VOLTAGE                          [V]           |    1    |         |         |         |         |         |
  0x0006, // SDM_PHASE_1_CURRENT                          [A]           |    1    |    1    |    1    |    1    |    1    |         |
  0x0008, // SDM_PHASE_2_CURRENT                          [A]           |    1    |         |         |         |         |         |
  0x000A, // SDM_PHASE_3_CURRENT                          [A]           |    1    |         |         |         |         |         |
  0x000C, // SDM_PHASE_1_POWER                            [W]           |    1    |    1    |    1    |    1    |    1    |         |
  0x000E, // SDM_PHASE_2_POWER                            [W]           |    1    |         |         |         |         |         |
  0x0010, // SDM_PHASE_3_POWER                            [W]           |    1    |         |         |         |         |         |
  0x0012, // SDM_PHASE_1_APPARENT_POWER                   [VA]          |    1    |    1    |    1    |    1    |    1    |         |
  0x0014, // SDM_PHASE_2_APPARENT_POWER                   [VA]          |    1    |         |         |         |         |         |
  0x0016, // SDM_PHASE_3_APPARENT_POWER                   [VA]          |    1    |         |         |         |         |         |
  0x0018, // SDM_PHASE_1_REACTIVE_POWER                   [VAr]         |    1    |    1    |    1    |    1    |    1    |         |
  0x001A, // SDM_PHASE_2_REACTIVE_POWER                   [VAr]         |    1    |         |         |         |         |         |
  0x001C, // SDM_PHASE_3_REACTIVE_POWER                   [VAr]         |    1    |         |         |         |         |         |
  0x001E, // SDM_PHASE_1_POWER_FACTOR                     [ ]           |    1    |    1    |    1    |    1    |    1    |         |
  0x0020, // SDM_PHASE_2_POWER_FACTOR                     [ ]           |    1    |         |         |         |         |         |
  0x0022, // SDM_PHASE_3_POWER_FACTOR                     [ ]           |    1    |         |         |         |         |         |
  0x0024, // SDM_PHASE_1_ANGLE                            [Degrees]     |    1    |    1    |    1    |    1    |         |         |
  0x0026, // SDM_PHASE_2_ANGLE                            [Degrees]     |    1    |         |         |         |         |         |
  0x0028, // SDM_PHASE_3_ANGLE                            [Degrees]     |    1    |         |         |         |         |         |
  0x002A, // SDM_AVERAGE_L_TO_N_VOLTS                     [V]           |    1    |         |         |         |         |         |
  0x002E, // SDM_AVERAGE_LINE_CURRENT                     [A]           |    1    |         |         |         |         |         |
  0x0030, // SDM_SUM_LINE_CURRENT                         [A]           |    1    |         |         |         |         |         |
  0x0034, // SDM_TOTAL_SYSTEM_POWER                       [W]           |    1    |         |         |         |         |    1    |
  0x0038, // SDM_TOTAL_SYSTEM_APPARENT_POWER              [VA]          |    1    |         |         |         |         |         |
  0x003C, // SDM_TOTAL_SYSTEM_REACTIVE_POWER              [VAr]         |    1    |         |         |         |         |         |
  0x003E, // SDM_TOTAL_SYSTEM_POWER_FACTOR                [ ]           |    1    |         |         |         |         |         |
  0x0042, // SDM_TOTAL_SYSTEM_PHASE_ANGLE                 [Degrees]     |    1    |         |         |         |         |         |
  0x0046, // SDM_FREQUENCY                                [Hz]          |    1    |    1    |    1    |    1    |    1    |         |
  0x0048, // SDM_IMPORT_ACTIVE_ENERGY                     [kWh/MWh]     |    1    |    1    |    1    |    1    |    1    |    1    |
  0x004A, // SDM_EXPORT_ACTIVE_ENERGY                     [kWh/MWh]     |    1    |    1    |    1    |    1    |    1    |    1    |
  0x004C, // SDM_IMPORT_REACTIVE_ENERGY                   [kVArh/MVArh] |    1    |    1    |    1    |    1    |    1    |         |
  0x004E, // SDM_EXPORT_REACTIVE_ENERGY                   [kVArh/MVArh] |    1    |    1    |    1    |    1    |    1    |         |
  0x0050, // SDM_VAH_SINCE_LAST_RESET                     [kVAh/MVAh]   |    1    |         |         |         |         |         |
  0x0052, // SDM_AH_SINCE_LAST_RESET                      [Ah/kAh]      |    1    |         |         |         |         |         |
  0x0054, // SDM_TOTAL_SYSTEM_POWER_DEMAND                [W]           |    1    |    1    |         |         |         |         |
  0x0056, // SDM_MAXIMUM_TOTAL_SYSTEM_POWER_DEMAND        [W]           |    1    |    1    |         |         |         |         |
  0x0058, // SDM_CURRENT_SYSTEM_POSITIVE_POWER_DEMAND     [W]           |         |    1    |         |         |         |         |
  0x005A, // SDM_MAXIMUM_SYSTEM_POSITIVE_POWER_DEMAND     [W]           |         |    1    |         |         |         |         |
  0x005C, // SDM_CURRENT_SYSTEM_REVERSE_POWER_DEMAND      [W]           |         |    1    |         |         |         |         |
  0x005E, // SDM_MAXIMUM_SYSTEM_REVERSE_POWER_DEMAND      [W]           |         |    1    |         |         |         |         |
  0x0064, // SDM_TOTAL_SYSTEM_VA_DEMAND                   [VA]          |    1    |         |         |         |         |         |
  0x0066, // SDM_MAXIMUM_TOTAL_SYSTEM_VA_DEMAND           [VA]          |    1    |         |         |         |         |         |
  0x0068, // SDM_NEUTRAL_CURRENT_DEMAND                   [A]           |    1    |         |         |         |         |         |
  0x006A, // SDM_MAXIMUM_NEUTRAL_CURRENT                  [A]           |    1    |         |         |         |         |         |
  0x00C8, // SDM_LINE_1_TO_LINE_2_VOLTS                   [V]           |    1    |         |         |         |         |         |
  0x00CA, // SDM_LINE_2_TO_LINE_3_VOLTS                   [V]           |    1    |         |         |         |         |         |
  0x00CC, // SDM_LINE_3_TO_LINE_1_VOLTS                   [V]           |    1    |         |         |         |         |         |
  0x00CE, // SDM_AVERAGE_LINE_TO_LINE_VOLTS               [V]           |    1    |         |         |         |         |         |
  0x00E0, // SDM_NEUTRAL_CURRENT                          [A]           |    1    |         |         |         |         |         |
  0x00EA, // SDM_PHASE_1_LN_VOLTS_THD                     [%]           |    1    |         |         |         |         |         |
  0x00EC, // SDM_PHASE_2_LN_VOLTS_THD                     [%]           |    1    |         |         |         |         |         |
  0x00EE, // SDM_PHASE_3_LN_VOLTS_THD                     [%]           |    1    |         |         |         |         |         |
  0x00F0, // SDM_PHASE_1_CURRENT_THD                      [%]           |    1    |         |         |         |         |         |
  0x00F2, // SDM_PHASE_2_CURRENT_THD                      [%]           |    1    |         |         |         |         |         |
  0x00F4, // SDM_PHASE_3_CURRENT_THD                      [%]           |    1    |         |         |         |         |         |
  0x00F8, // SDM_AVERAGE_LINE_TO_NEUTRAL_VOLTS_THD        [%]           |    1    |         |         |         |         |         |
  0x00FA, // SDM_AVERAGE_LINE_CURRENT_THD                 [%]           |    1    |         |         |         |         |         |
  0x00FE, // SDM_TOTAL_SYSTEM_POWER_FACTOR_INV            [ ]           |    1    |         |         |         |         |         |
  0x0102, // SDM_PHASE_1_CURRENT_DEMAND                   [A]           |    1    |    1    |         |         |         |         |
  0x0104, // SDM_PHASE_2_CURRENT_DEMAND                   [A]           |    1    |         |         |         |         |         |
  0x0106, // SDM_PHASE_3_CURRENT_DEMAND                   [A]           |    1    |         |         |         |         |         |
  0x0108, // SDM_MAXIMUM_PHASE_1_CURRENT_DEMAND           [A]           |    1    |    1    |         |         |         |         |
  0x010A, // SDM_MAXIMUM_PHASE_2_CURRENT_DEMAND           [A]           |    1    |         |         |         |         |         |
  0x010C, // SDM_MAXIMUM_PHASE_3_CURRENT_DEMAND           [A]           |    1    |         |         |         |         |         |
  0x014E, // SDM_LINE_1_TO_LINE_2_VOLTS_THD               [%]           |    1    |         |         |         |         |         |
  0x0150, // SDM_LINE_2_TO_LINE_3_VOLTS_THD               [%]           |    1    |         |         |         |         |         |
  0x0152, // SDM_LINE_3_TO_LINE_1_VOLTS_THD               [%]           |    1    |         |         |         |         |         |
  0x0154, // SDM_AVERAGE_LINE_TO_LINE_VOLTS_THD           [%]           |    1    |         |         |         |         |         |
  0x0156, // SDM_TOTAL_ACTIVE_ENERGY                      [kWh]         |    1    |    1    |    1    |    1    |    1    |    1    |
  0x0158, // SDM_TOTAL_REACTIVE_ENERGY                    [kVArh]       |    1    |    1    |    1    |    1    |    1    |         |
  0x015A, // SDM_L1_IMPORT_ACTIVE_ENERGY                  [kWh]         |    1    |         |         |         |         |         |
  0x015C, // SDM_L2_IMPORT_ACTIVE_ENERGY                  [kWh]         |    1    |         |         |         |         |         |
  0x015E, // SDM_L3_IMPORT_ACTIVE_ENERGY                  [kWh]         |    1    |         |         |         |         |         |
  0x0160, // SDM_L1_EXPORT_ACTIVE_ENERGY                  [kWh]         |    1    |         |         |         |         |         |
  0x0162, // SDM_L2_EXPORT_ACTIVE_ENERGY                  [kWh]         |    1    |         |         |         |         |         |
  0x0164, // SDM_L3_EXPORT_ACTIVE_ENERGY                  [kWh]         |    1    |         |         |         |         |         |
  0x0166, // SDM_L1_TOTAL_ACTIVE_ENERGY                   [kWh]         |    1    |         |         |         |         |         |
  0x0168, // SDM_L2_TOTAL_ACTIVE_ENERGY                   [kWh]         |    1    |         |         |         |         |         |
  0x016a, // SDM_L3_TOTAL_ACTIVE_ENERGY                   [kWh]         |    1    |         |         |         |         |         |
  0x016C, // SDM_L1_IMPORT_REACTIVE_ENERGY                [kVArh]       |    1    |         |         |         |         |         |
  0x016E, // SDM_L2_IMPORT_REACTIVE_ENERGY                [kVArh]       |    1    |         |         |         |         |         |
  0x0170, // SDM_L3_IMPORT_REACTIVE_ENERGY                [kVArh]       |    1    |         |         |         |         |         |
  0x0172, // SDM_L1_EXPORT_REACTIVE_ENERGY                [kVArh]       |    1    |         |         |         |         |         |
  0x0174, // SDM_L2_EXPORT_REACTIVE_ENERGY                [kVArh]       |    1    |         |         |         |         |         |
  0x0176, // SDM_L3_EXPORT_REACTIVE_ENERGY                [kVArh]       |    1    |         |         |         |         |         |
  0x0178, // SDM_L1_TOTAL_REACTIVE_ENERGY                 [kVArh]       |    1    |         |         |         |         |         |
  0x017A, // SDM_L2_TOTAL_REACTIVE_ENERGY                 [kVArh]       |    1    |         |         |         |         |         |
  0x017C, // SDM_L3_TOTAL_REACTIVE_ENERGY                 [kVArh]       |    1    |         |         |         |         |         |
  0x0180, // SDM_CURRENT_RESETTABLE_TOTAL_ACTIVE_ENERGY   [kWh]         |         |    1    |         |         |         |    1    |
  0x0182, // SDM_CURRENT_RESETTABLE_TOTAL_REACTIVE_ENERGY [kVArh]       |         |    1    |         |         |         |         |
  0x0184, // SDM_CURRENT_RESETTABLE_IMPORT_ENERGY         [kWh]         |         |         |         |         |         |    1    |
  0x0186, // SDM_CURRENT_RESETTABLE_EXPORT_ENERGY         [kWh]         |         |         |         |         |         |    1    |
  0x0500, // SDM_IMPORT_POWER                             [W]           |         |         |         |         |         |    1    |
  0x0502  // SDM_EXPORT_POWER                             [W]           |         |         |         |         |         |    1    |
};
