/*
Armator - simulateur de jeu d'instruction ARMv5T � but p�dagogique
Copyright (C) 2011 Guillaume Huard
Ce programme est libre, vous pouvez le redistribuer et/ou le modifier selon les
termes de la Licence Publique G�n�rale GNU publi�e par la Free Software
Foundation (version 2 ou bien toute autre version ult�rieure choisie par vous).

Ce programme est distribu� car potentiellement utile, mais SANS AUCUNE
GARANTIE, ni explicite ni implicite, y compris les garanties de
commercialisation ou d'adaptation dans un but sp�cifique. Reportez-vous � la
Licence Publique G�n�rale GNU pour plus de d�tails.

Vous devez avoir re�u une copie de la Licence Publique G�n�rale GNU en m�me
temps que ce programme ; si ce n'est pas le cas, �crivez � la Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307,
�tats-Unis.

Contact: Guillaume.Huard@imag.fr
	 B�timent IMAG
	 700 avenue centrale, domaine universitaire
	 38401 Saint Martin d'H�res
*/
#ifndef __ARM_CONSTANTS_H__
#define __ARM_CONSTANTS_H__
#include <stdint.h>

/* ARM Modes */
#define USR 0x10
#define FIQ 0x11
#define IRQ 0x12
#define SVC 0x13
#define ABT 0x17
#define UND 0x1b
#define SYS 0x1f

/* Normal executation output */
#define SUCCESSFULLY_DECODED 0

/* ARM Exceptions (by priority) */
#define RESET                   1
#define DATA_ABORT              2
#define FAST_INTERRUPT          3
#define INTERRUPT               4
#define IMPRECISE_ABORT         5	// Unsupported, ARMV6
#define PREFETCH_ABORT          6
#define UNDEFINED_INSTRUCTION   7
#define SOFTWARE_INTERRUPT      8
/* The last one is not realy an exception, but, as we handle software interrupts
 * within the simulator and we decide there to end the simulation, this is a way
 * to tell it to the outside world
 */
#define END_SIMULATION          9

/* Some CPSR bits */
#define N 31
#define Z 30
#define C 29
#define V 28

/* shift operations */
#define LSL 0
#define LSR 1
#define ASR 2
#define ROR 3

/* conditions */
#define EQ 0
#define NE 1
#define HS 2
#define LO 3
#define MI 4
#define PL 5
#define VS 6
#define VC 7
#define HI 8
#define LS 9
#define GE 10
#define LT 11
#define GT 12
#define LE 13
#define AL 14

/* data processing instructions */
#define AND 0
#define EOR 1
#define SUB 2
#define RSB 3
#define ADD 4
#define ADC 5
#define SBC 6
#define RSC 7
#define TST 8
#define TEQ 9
#define CMP 10
#define CMN 11
#define ORR 12
#define MOV 13
#define BIC 14
#define MVN 15

/* data processing instruction's masks */
#define COND_MASK ((uint32_t)0xF << 28)
#define INSTR_MASK ((uint32_t)3 << 26)
#define I_MASK ((uint32_t)1 << 25)
#define OPCODE_MASK ((uint32_t)0xF << 21)
#define S_MASK ((uint32_t)1 << 20)
#define RN_MASK ((uint32_t)0xF << 16)
#define RD_MASK ((uint32_t)0xF << 12)
#define SHIFTER_OPERAND_MASK (uint32_t)0xFFF

/* Bit mask constants for msr */
/* We simulate architecture v5T */
#define UnallocMask 0x0FFFFF00
#define UserMask    0xF0000000
#define PrivMask    0x0000000F
#define StateMask   0x00000020

char *arm_get_exception_name(unsigned char exception);
char *arm_get_mode_name(uint8_t mode);
int8_t arm_get_mode_number(char *name);
char *arm_get_register_name(uint8_t reg);

#endif
