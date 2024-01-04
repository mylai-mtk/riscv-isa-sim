reg_t tmp = npc;
set_pc((RS1 + insn.i_imm()) & ~reg_t(1));
WRITE_RD(tmp);

if (p->extension_enabled(EXT_ZICFILP)) {
  if (ZICFILP_READ_XLPE(STATE.v, STATE.prv)) {
    STATE.elp = ZICFILP_EXPECT_LP(insn.rs1());
  }
}

