require(STATE.debug_mode);
set_pc_and_serialize(STATE.dpc->read());
if (p->extension_enabled(EXT_ZICFILP)) {
  if (ZICFILP_READ_XLPE(STATE.dcsr->v, STATE.dcsr->prv)) {
    STATE.elp = STATE.dcsr->pelp;
  } else {
    STATE.elp = elp_t::NO_LP_EXPECTED;
  }
}
p->set_privilege(STATE.dcsr->prv, STATE.dcsr->v);
if (STATE.prv < PRV_M)
  STATE.mstatus->write(STATE.mstatus->read() & ~MSTATUS_MPRV);

/* We're not in Debug Mode anymore. */
STATE.debug_mode = false;

if (STATE.dcsr->step)
  STATE.single_step = STATE.STEP_STEPPING;
