require_extension(EXT_ZCA);
require(insn.rvc_rs1() != 0);
reg_t tmp = npc;
set_pc(RVC_RS1 & ~reg_t(1));
WRITE_REG(X_RA, tmp);

if (p->extension_enabled(EXT_ZICFILP)) {
  if (ZICFILP_READ_XLPE(STATE.v, STATE.prv)) {
    STATE.elp = ZICFILP_EXPECT_LP(insn.rvc_rs1());
  }
}

