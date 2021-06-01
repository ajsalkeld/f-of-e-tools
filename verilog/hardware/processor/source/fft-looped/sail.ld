OUTPUT_FORMAT("elf32-littleriscv")
OUTPUT_ARCH(riscv)

ENTRY(_start)

SECTIONS
{
	. = 0x00;
	.text . :
	{
		_text = . ;
		*(.text) 
		. = 0x6400;
		*(.strings)
		_etext = . ;
	}

	.data . :
	{
		*(.data)
	}

	.bss . :
	{ 
		*(.bss)
	}
}
