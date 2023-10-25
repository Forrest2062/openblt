/**
 * \file IfxGtm_Trig.c
 * \brief GTM TRIG details
 *
 * \version iLLD_1_0_1_16_1
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxGtm_Trig.h"
#include "_Utilities/Ifx_Assert.h"
#include "Cpu/Std/IfxCpu_Intrinsics.h"

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \addtogroup IfxLld_Gtm_Trig_Data_Structures
 * \{ */
typedef struct
{
    sint8 config;       /**< \brief Value for SEL0/1. config=0xFF means "not available" */
} IfxGtm_Trig_Channel;

/** \} */

/** \addtogroup IfxLld_Gtm_Trig_Data_Structures
 * \{ */
typedef struct
{
    IfxGtm_Trig_Channel channel[IfxGtm_Trig_AdcTrigChannel_count];
} IfxGtm_Trig_Source;

/** \} */

/** \addtogroup IfxLld_Gtm_Trig_Data_Structures
 * \{ */
typedef struct
{
    IfxGtm_Trig_Source source[IfxGtm_Trig_AdcTrigSource_count];
} IfxGtm_Trig_Trigger;

/** \} */

/** \addtogroup IfxLld_Gtm_Trig_Data_Structures
 * \{ */
typedef struct
{
    IfxGtm_Trig_Trigger trigger[IfxGtm_Trig_AdcTrig_count];
} IfxGtm_Trig_AdcTrig_Table;

/** \} */

/******************************************************************************/
/*------------------------Private Variables/Constants-------------------------*/
/******************************************************************************/

IFX_STATIC IFX_CONST IfxGtm_Trig_AdcTrig_Table IfxGtm_Trig_AdcTrig_tableAdc0_1_2 = {
    .trigger = {
        {.source = {                                                                                                                                                                //IfxGtm_AdcTrig_0
                  //{.channel = {     {Channel_4     }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07}, {.config = 0x08}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0x09}, {.config = 0x0A}, {.config = 0x0B}, {.config = 0x0C}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom3

                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01}, {.config = 0x02}, {.config = 0x03}, {.config = 0x04}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_tom1
              }},
        {.source = {                                                                                                                                                                //IfxGtm_AdcTrig_1
                  //{.channel = {     {Channel_4     }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0x0B}, {.config = 0x0C}, {.config = 0x0D}, {.config = 0x0E}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07}, {.config = 0x08}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom3

                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0x09}, {.config = 0x0A}}},                 //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01}, {.config = 0x02}, {.config = 0x03}, {.config = 0x04}, {.config = 0xFF}}},                 //IfxGtm_AdcTrigSource_tom1
              }}
    }
};

IFX_STATIC IFX_CONST IfxGtm_Trig_AdcTrig_Table IfxGtm_Trig_AdcTrig_tableAdc3_4 = {
    .trigger = {
        {.source = {                                                                                                                                                //IfxGtm_AdcTrig_0
                  //             IfxGtm_AdcTrig
                  //{.channel = {     {Channel_4     }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07}, {.config = 0x08}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0x0B}, {.config = 0x0C}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0x0D}, {.config = 0x0E}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3

                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01}, {.config = 0x02}, {.config = 0x03}, {.config = 0x04}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x09}, {.config = 0x0A}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }},
        {.source = {                                                                                                                                                //IfxGtm_AdcTrig_1
                  //{.channel = {     {Channel_4     }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07}, {.config = 0x08}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x0B}, {.config = 0x0C}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x0D}, {.config = 0x0E}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3

                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01}, {.config = 0x02}, {.config = 0x03}, {.config = 0x04}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }}
    }
};

IFX_STATIC IFX_CONST IfxGtm_Trig_AdcTrig_Table IfxGtm_Trig_AdcTrig_tableAdc5_6_7 = {
    .trigger = {
        {.source = {                                                                                                                                                                    //IfxGtm_AdcTrig_0
                  //             IfxGtm_AdcTrig
                  //{.channel = {     {Channel_4     }, {Channel_5     }, {Channel_6               }, {Channel_7               }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07          }, {.config = 0x08          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0x0D}, {.config = 0x0E}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3
                  {.channel = {     {.config = 0x0B}, {.config = 0x0C}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4

                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01 /*0x09 */}, {.config = 0x02 /*0x0A */}, {.config = 0x03}, {.config = 0x04}, {.config = 0x0F}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }},
        {.source = {                                                                                                                                                                    //IfxGtm_AdcTrig_1
                  //{.channel = {     {Channel_4     }, {Channel_5     }, {Channel_6               }, {Channel_7               }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07          }, {.config = 0x08          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x0D          }, {.config = 0x0E          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x0B          }, {.config = 0x0C          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4

                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0x09}, {.config = 0x0A}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01          }, {.config = 0x02          }, {.config = 0x03}, {.config = 0x04}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }}
    }
};

IFX_STATIC IFX_CONST IfxGtm_Trig_AdcTrig_Table IfxGtm_Trig_AdcTrig_tableAdc8 = {
    .trigger = {
        {.source = {                                                                                                                                                                    //IfxGtm_AdcTrig_0
                  //             IfxGtm_AdcTrig
                  //{.channel = {{Channel_4     }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0x0B}, {.config = 0x0C}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01 /*0x09 */}, {.config = 0x02 /*0x0A */}, {.config = 0x03}, {.config = 0x04}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }},
        {.source = {                                                                                                                                                                    //IfxGtm_AdcTrig_1
                  //{.channel = {{Channel_4     }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0x05}, {.config = 0x06}, {.config = 0x07 /*0x0B */}, {.config = 0x08 /*0x0C */}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF          }, {.config = 0xFF          }, {.config = 0xFf}, {.config = 0x09}, {.config = 0x0A}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x01          }, {.config = 0x02          }, {.config = 0x03}, {.config = 0x04}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }}
    }
};

/** \brief Trigger table for SENT triggers
 */
IFX_STATIC IFX_CONST IfxGtm_Trig_AdcTrig_Table IfxGtm_Trig_SentTrig_table = {
    .trigger = {
        {.source = {                                                                                                                                                //IfxGtm_AdcTrig_0
                  //{.channel =     {{Channel_4    }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0x04}, {.config = 0x05}, {.config = 0x06}, {.config = 0x07}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0x00}, {.config = 0x01}, {.config = 0x02}, {.config = 0x03}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }},
        {.source = {                                                                                                                                                //IfxGtm_AdcTrig_1
                  //{.channel =     {{Channel_4    }, {Channel_5     }, {Channel_6     }, {Channel_7     }, {Channel_13    }, {Channel_14    }, {Channel_15    }}},
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom1
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom2
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom3
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_atom4
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom0
                  {.channel = {     {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}, {.config = 0xFF}}}, //IfxGtm_AdcTrigSource_tom1
              }}
    }
};

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

boolean IfxGtm_Trig_fromDsadc(Ifx_GTM *gtm, uint32 dsadcChannel, IfxGtm_Tim tim, IfxGtm_Tim_Ch timChannel)
{
    boolean result = dsadcChannel <= 5;

    if (result != FALSE)
    {
        uint32 mask = 0xFU << (timChannel * 4);
        __ldmst_c(&(gtm->INOUTSEL.DSADC.INSEL[tim].U), mask, dsadcChannel << (timChannel * 4));
    }

    return result;
}


void IfxGtm_Trig_toDsadc(Ifx_GTM *gtm, uint32 dsadcChannel, IfxGtm_Trig_DsadcTrig dsadcTrig, IfxGtm_Trig_DsadcTrigSource sel)
{
    uint32 shift = (dsadcChannel % 8) * 4;
    uint32 mask  = 0xFU << shift;
    uint32 value = sel << shift;

    switch (dsadcTrig)
    {
    case IfxGtm_Trig_DsadcTrig_0:
        __ldmst_c(&(gtm->INOUTSEL.DSADC.OUTSEL00.U), mask, value);
        break;
    case IfxGtm_Trig_DsadcTrig_1:
        __ldmst_c(&(gtm->INOUTSEL.DSADC.OUTSEL10.U), mask, value);
        break;
    }
}


boolean IfxGtm_Trig_toVadc(Ifx_GTM *gtm, IfxGtm_Trig_AdcGroup adcGroup, IfxGtm_Trig_AdcTrig adcTrig, IfxGtm_Trig_AdcTrigSource source, IfxGtm_Trig_AdcTrigChannel channel)
{
    IFX_CONST IfxGtm_Trig_AdcTrig_Table *table = NULL_PTR;
    uint8                                config;

    boolean                              result = 0;

    switch (adcGroup)
    {
    case IfxGtm_Trig_AdcGroup_0:
    case IfxGtm_Trig_AdcGroup_1:
    case IfxGtm_Trig_AdcGroup_2:
        table = &IfxGtm_Trig_AdcTrig_tableAdc0_1_2;
        break;
    case IfxGtm_Trig_AdcGroup_3:
    case IfxGtm_Trig_AdcGroup_4:
        table = &IfxGtm_Trig_AdcTrig_tableAdc3_4;
        break;
    case IfxGtm_Trig_AdcGroup_5:
    case IfxGtm_Trig_AdcGroup_6:
    case IfxGtm_Trig_AdcGroup_7:
        table = &IfxGtm_Trig_AdcTrig_tableAdc5_6_7;
        break;
    case IfxGtm_Trig_AdcGroup_8:
        table = &IfxGtm_Trig_AdcTrig_tableAdc8;
        break;
    default:
        break;
    }

    if (table != NULL_PTR)
    {
        config = table->trigger[adcTrig].source[source].channel[channel].config;
        result = config != 0xFF;
        uint32 shift = (adcGroup % 8) * 4;
        uint32 mask  = 0xFU << shift;
        uint32 value = config << shift;

        switch (adcTrig)
        {
        case IfxGtm_Trig_AdcTrig_0:

            if ((adcGroup / 8) == 0)
            {
                __ldmst_c(&(gtm->ADCTRIG0OUT0.U), mask, value);
            }
            else
            {
                __ldmst_c(&(gtm->ADCTRIG0OUT1.U), mask, value);
            }

            break;
        case IfxGtm_Trig_AdcTrig_1:

            if ((adcGroup / 8) == 0)
            {
                __ldmst_c(&(gtm->ADCTRIG1OUT0.U), mask, value);
            }
            else
            {
                __ldmst_c(&(gtm->ADCTRIG1OUT1.U), mask, value);
            }

            break;
        default:
            result = FALSE;
            break;
        }
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, result);

    return result;
}


boolean IfxGtm_Trig_toSent(Ifx_GTM *gtm, IfxGtm_Trig_SentGroup sentGroup, IfxGtm_Trig_SentTrig sentTrig, IfxGtm_Trig_SentTrigSource source, IfxGtm_Trig_SentTrigChannel channel)
{
    IFX_CONST IfxGtm_Trig_AdcTrig_Table *table = NULL_PTR;
    uint8                                config;
    uint32                               shift, mask, value;
    boolean                              result = 0;

    switch (sentGroup)
    {
    case IfxGtm_Trig_SentGroup_0:
    case IfxGtm_Trig_SentGroup_1:
    case IfxGtm_Trig_SentGroup_2:
        table = &IfxGtm_Trig_AdcTrig_tableAdc0_1_2;
        break;
    case IfxGtm_Trig_SentGroup_3:
    case IfxGtm_Trig_SentGroup_4:
        table = &IfxGtm_Trig_AdcTrig_tableAdc3_4;
        break;
    case IfxGtm_Trig_SentGroup_5:
    case IfxGtm_Trig_SentGroup_6:
    case IfxGtm_Trig_SentGroup_7:
        table = &IfxGtm_Trig_AdcTrig_tableAdc5_6_7;
        break;
    case IfxGtm_Trig_SentGroup_8:
        table = &IfxGtm_Trig_AdcTrig_tableAdc8;
        break;
    case IfxGtm_Trig_SentGroup_9:
        table = &IfxGtm_Trig_SentTrig_table;
        break;
    default:
        break;
    }

    if (table != NULL_PTR)
    {
        config = table->trigger[sentTrig].source[source].channel[channel].config;
        result = config != 0xFF;

        if ((sentGroup / 9) == 0) // write to VADC registers
        {
            shift = (sentGroup % 8) * 4;
        }
        else            // write to DSADC registers
        {
            shift = (sentGroup % 9) * 4;
        }

        mask  = 0xFU << shift;
        value = config << shift;

        if ((sentGroup / 9) == 0) // write to VADC registers
        {
            if ((sentGroup / 8) == 0)
            {
                __ldmst_c(&(gtm->ADCTRIG0OUT0.U), mask, value);
            }
            else
            {
                __ldmst_c(&(gtm->ADCTRIG0OUT1.U), mask, value);
            }
        }
        else                // write to DSADC registers
        {
            __ldmst_c(&(gtm->INOUTSEL.DSADC.OUTSEL00.U), mask, value);
        }
    }

    IFX_ASSERT(IFX_VERBOSE_LEVEL_ERROR, result);

    return result;
}
