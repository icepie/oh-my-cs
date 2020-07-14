import os

exit_code = os.system('ping hmgr.sec.lit.edu.cn')
if exit_code:
    raise Exception('connect failed.')
