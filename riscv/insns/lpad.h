if (p->extension_enabled(EXT_ZICFILP)) {
  if (ZICFILP_READ_XLPE(STATE.v, STATE.prv) && STATE.elp == elp_t::LP_EXPECTED) {
    software_check(pc % 4 == 0 &&
                   ((READ_REG(7) >> 12) == insn.u_imm() || insn.u_imm() == 0),
                   SCE_XTVAL_LANDING_PAD_FAULT);
    STATE.elp = elp_t::NO_LP_EXPECTED;
  }
}

