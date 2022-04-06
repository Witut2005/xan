

void add(void);
void add_ax(void);
void push_es(void);
void pop_es(void);
void _or(void);
void _or_ax(void);
void push_cs(void);
void bad_opcode(void);
void adc(void);
void adc_ax(void);
void push_ss(void);
void pop_ss(void);
void sbb(void);
void sbb_ax(void);
void push_ds(void);
void pop_ds(void);
void _and(void);
void _and_ax(void);
void es_override(void);
void daa(void);
void sub(void);
void sub_ax(void);
void cs_override(void);
void das(void);
void _xor(void);
void _xor_ax(void);
void ss_override(void);
void aaa(void);
void cmp(void);
void cmp_ax(void);
void ds_override(void);
void aas(void);
void inc(void);
void dec(void);
void push(void);
void pop(void);
void jo(void);
void jno(void);
void jc(void);
void jnc(void);
void jz(void);
void jnz(void);
void jna(void);
void ja(void);
void js(void);
void jns(void);
void jp(void);
void jnp(void);
void jl(void);
void jnl(void);
void jle(void);
void jnle(void);

void op80x(void);
void op81x(void);
void op82x(void);
void op83x(void);

void test(void);

void xchg(void);

void mov(void);
void mov_segment(void);
void lea(void);

void pop(void);

void xchg_ax(void);

void cbw(void);
void cwd(void);
void call_far(void);
void wait(void);
void pushf(void);

void popf(void);
void sahf(void);
void lahf(void);

void mov_ax(void);

void movs(void);

void cmps(void);

void test_ax(void);

void stos(void);
void lods(void);
void scas(void);


void mov_immediate(void);

void retn(void);
void ret(void);
void les(void);
void lds(void);                 //0xC5
void mov_memory(void);
void ret_immediate16(void);
void debug_interrupt(void);
void int_immediate(void);
void into(void);
void iret(void);
void opD0x(void);
void opD1x(void);
void opD2x(void);
void opD3x(void);
void aam(void);
void aad(void);
void xlat(void);
void esc(void);
void loopne(void);
void loope(void);
void loop(void);
void jcxz(void);
void in(void);
void out(void);
void call_near(void);
void jmp_near(void);
void jmp_far(void);
void jmp_short(void);
void lock(void);
void repne(void);
void rep(void);
void hlt(void);
void cmc(void);
void opF6x(void);
void opF7x(void);

void clc(void);
void stc(void);
void cli(void);
void sti(void);
void cld(void);
void _std(void);
void opFEx(void);
void opFFx(void);
