import os

exit_code = os.system('http://hmgr.sec.lit.edu.cn/wms/healthyLogin')
if exit_code:
    raise Exception('connect failed.')
