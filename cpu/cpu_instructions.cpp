
#include <iostream>
#include <cpu/cpu_instructions.hpp>
#include <cpu/cpu.hpp>

uint64_t check_parity(uint64_t arg)
{
    
    auto result = 0;

    for(int i = 0x0; i < sizeof(arg) * 8; i++)
    {
        result = result + arg % 2;
        arg = arg / 2;
    }

    return (result & 1) == 0;

}

void add(void){}
void add_ax(void)
{
    if(machine_code->w)
    {
        cpu->ax += (uint16_t)(machine_code->byte1 << 8) | machine_code->byte2;
        cpu->ip += 3;
    }

    else 
    {
        cpu->al += machine_code->byte1;
        cpu->ip += 2;
    }
}

void push_es(void){}
void pop_es(void){}
void _or(void){}
void _or_ax(void){}
void push_cs(void){}
void bad_opcode(void)
{
    std::cout << "bad_opcode" << std::endl;
    exit(1);
}

void adc(void){}
void adc_ax(void){}
void push_ss(void){}
void pop_ss(void){}
void sbb(void){}
void sbb_ax(void){}
void push_ds(void){}
void pop_ds(void){}
void _and(void){}
void _and_ax(void){}
void es_override(void){}
void daa(void){}
void sub(void){}
void sub_ax(void)
{
    if(machine_code->w)
    {
        cpu->ax -= (uint16_t)(machine_code->byte1 << 8) | machine_code->byte2;
        cpu->ip += 3;
    }

    else 
    {
        cpu->al -= machine_code->byte1;
        cpu->ip += 2;
    }
}

void cs_override(void){}
void das(void){}
void _xor(void){}

void _xor_ax(void)
{
    if(machine_code->w)
    {
        cpu->ax = cpu->ax ^ static_cast<uint16_t>(machine_code->byte1 | (machine_code->byte2 << 8));
        cpu->ip += 3;
    }

    else 
    {
        cpu->al = static_cast<uint8_t>(machine_code->byte1);
        cpu->ip += 2;
    }

}

void ss_override(void){}
void aaa(void){}
void cmp(void){}
void cmp_ax(void)
{
    if(!(cpu->ax - static_cast<uint8_t>(machine_code->byte1)))
    {
        cpu->flags.zf = 1;
    }
}

void ds_override(void){}
void aas(void){}
void inc(void)
{
    cpu->registers[machine_code->byte0 & 0x7].bit16++;
    cpu->ip++; 
}
void dec(void)
{
    cpu->registers[machine_code->byte0 & 0x7].bit16--;
    cpu->ip++; 
}

void push(void){}
void pop(void){}
void jo(void){}
void jno(void){}
void jc(void){}
void jnc(void){}
void jz(void){}
void jnz(void){}
void jna(void){}
void ja(void){}
void js(void){}
void jns(void){}
void jp(void){}
void jnp(void){}
void jl(void){}
void jnl(void){}
void jle(void){}
void jnle(void){}
void op80x(void){}
void op81x(void){}
void op82x(void){}
void op83x(void){}

void test(void){}

void xchg(void){}

void mov(void){}
void mov_segment(void){}
void lea(void){}

void xchg_ax(void)
{

    uint16_t tmp = cpu->ax;
    cpu->ax = cpu->registers[machine_code->byte0 & 0x7].bit16;
    cpu->registers[machine_code->byte0 & 0x7].bit16 = tmp;
    cpu->ip++;

}

void cbw(void){}
void cwd(void){}
void call_far(void){}
void wait(void){}
void pushf(void){}

void popf(void){}
void sahf(void){}
void lahf(void){}

void mov_ax(void)
{
    if(machine_code->w)
    {
        cpu->ax = (uint16_t)(machine_code->byte1 << 8) | machine_code->byte2;
        cpu->ip += 3;
    }

    else 
    {
        cpu->al = machine_code->byte1;
        cpu->ip += 2;
    }
}

void movs(void){}

void cmps(void){}

void test_ax(void){}

void stos(void){}
void lods(void){}
void scas(void){}


void mov_immediate(void){}

void retn(void){}
void ret(void){}
void les(void){}
void lds(void){}                 //0xC5
void mov_memory(void){}
void ret_immediate16(void){}
void debug_interrupt(void){}
void int_immediate(void){}
void into(void){}
void iret(void){}
void opD0x(void){}
void opD1x(void){}
void opD2x(void){}
void opD3x(void){}
void aam(void){}
void aad(void){}
void xlat(void){}
void esc(void){}
void loopne(void){}
void loope(void){}
void loop(void){}
void jcxz(void){}
void in(void){}
void out(void){}
void call_near(void){}
void jmp_near(void){}
void jmp_far(void){}
void jmp_short(void){}
void lock(void){}
void repne(void){}
void rep(void){}
void hlt(void){}
void cmc(void){}
void opF6x(void){}
void opF7x(void){}

void clc(void){}
void stc(void){}
void cli(void){}
void sti(void){}
void cld(void){}
void _std(void){}
void opFEx(void){}
void opFFx(void){}


processor_instructions instruction_set[256]
{

    add,        
    add,
    add,
    add,
    add_ax,
    add_ax,                  //0x5
    
    push_es,
    pop_es,                  //0x7
    
    _or,
    _or,
    _or,
    _or,
    _or_ax,
    _or_ax,                    //0xd
    
    push_cs,                  //0xe
    bad_opcode,              //0xf
    
    adc,
    adc,
    adc,
    adc,                     //0x13
    adc_ax,
    adc_ax,                   //0x15
    
    push_ss,
    pop_ss,                   //0x17
    
    sbb,
    sbb,
    sbb,
    sbb,                     //0x1b
    sbb_ax,
    sbb_ax,                   //0x1d
    
    push_ds,
    pop_ds,                   //0x1f
    
    _and,
    _and,
    _and,
    _and,             //0x23
    _and_ax,
    _and_ax,                 //0x25
    
    es_override,                       //0x26     <-- segment override prefix
    
    daa,                         //0x27
    
    sub,
    sub,
    sub,
    sub,             //0x2b
    sub_ax,
    sub_ax,                 //0x2d
    
    cs_override,                       //0x2e     <-- segment override prefix
    
    das,                         //0x2f
    
    _xor,
    _xor,
    _xor,
    _xor,             //0x33
    _xor_ax,
    _xor_ax,                 //0x35
    
    ss_override,                       //0x36     <-- segment override prefix
    
    aaa,                         //0x37
    
    cmp,
    cmp,
    cmp,
    cmp,             //0x3b
    cmp_ax,
    cmp_ax,                 //0x3d
    
    ds_override,                       //0x3e     <-- segment override prefix
    
    aas,                         //0x3f
    
    inc,
    inc,
    inc,
    inc,
    inc,
    inc,
    inc,
    inc,             //0x47

    dec,
    dec,
    dec,
    dec,
    dec,
    dec,
    dec,
    dec,             //0x4f
    
    push,
    push,
    push,
    push,
    push,
    push,
    push,
    push,         //0x57

    pop,
    pop,
    pop,
    pop,
    pop,
    pop,
    pop,
    pop,             //0x5f

    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,    //0x67
    
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,
    bad_opcode,    //0x6f
    

    jo,
    jno,
    jc,
    jnc,
    jz,
    jnz,
    jna,
    ja,
    js,
    jns,
    jp,
    jnp,
    jl,
    jnl,
    jle
    ,jnle,  //0x7f

    op80x,
    op81x,
    op82x,
    op83x,    //0x83

    test,
    test,                  //0x85

    xchg,
    xchg,                  //0x87

    mov,
    mov,
    mov,
    mov,            //0x8b
    mov_segment,                     //0x8c  BAD OPCODE 1xx for reg field


    lea,                        //0x8d
    mov_segment,                     //0x8e  BAD OPCODE 1xx for reg field


    pop,                        //0x8f  BAD OPCODE for reg != 0



    
    xchg_ax, // nop              //0x90
    
    xchg_ax,
    xchg_ax,
    xchg_ax,
    xchg_ax,//0x94
    xchg_ax,
    xchg_ax,
    xchg_ax,       //0x97

    cbw,                        //0x98
    cwd,                        //0x99

    call_far, //far_proc         //0x9a

    wait,                       //0x9b
    pushf,                      //0x9c
    popf,                       //0x9d
    sahf,                       //0x9e
    lahf,                       //0x9f

    mov_ax,
    mov_ax,                //0xA1
    mov_ax,
    mov_ax,                //0xA3

    movs,movs,                  //0xA5

    cmps,cmps,                  //0xA7

    test_ax,test_ax,              //0xA9

    stos,stos,                  //0xAB

    lods,lods,                  //0xAD

    scas,scas,                  //0xAF


    mov_immediate,
    mov_immediate,
    mov_immediate,
    mov_immediate,//0xB3
    mov_immediate,
    mov_immediate,
    mov_immediate,
    mov_immediate,//0xB7
    mov_immediate,
    mov_immediate,
    mov_immediate,
    mov_immediate,//0xBB
    mov_immediate,
    mov_immediate,
    mov_immediate,
    mov_immediate,//0xBF

    bad_opcode,
    bad_opcode,      //0xC1

    retn,                       //0xC2  intrasegment
    ret,                        //0xC3  intrasegment
    les,                        //0xC4
    lds,                        //0xC5
    mov_memory,                     //0xC6  reg must be 0
    mov_memory,                     //0xC7 reg must be 0

    bad_opcode,
    bad_opcode,      //0xC9
    ret_immediate16,                   //0xCA  intersegment
    ret,                        //0xCB  intersegment

    debug_interrupt,                       //0xCC
    int_immediate,                     //0xCD
    into,                       //0xCE
    iret,                       //0xCF
    opD0x,                      //0xD0
    opD1x,                      //0xD1
    opD2x,                      //0xD2      
    opD3x,                      //0xD3
    aam,                        //0xD4
    aad,                        //0xD5
    bad_opcode,                 //0xD6
    xlat,                       //0xD7
    esc,                        //0xD8 - 0xDF
    esc,
    esc,
    esc,
    esc,            // imo jeszcze jeden esc
    esc,
    esc,
    esc,
    loopne,                     //0xE0
    loope,                      //0xE1
    loop,                       //0xE2
    jcxz,                        //0xE3
    in,in,
    out,out,
    call_near,
    jmp_near,
    jmp_far,
    jmp_short,
    in,in,
    out,out,
    lock,
    bad_opcode,
    repne,
    rep,
    hlt,
    cmc,
    opF6x,                       //REG cannot be 1
    opF7x,                       //REG cannot be 1
    clc,
    stc,
    cli,
    sti,
    cld,
    _std,
    opFEx,
    opFFx
};
