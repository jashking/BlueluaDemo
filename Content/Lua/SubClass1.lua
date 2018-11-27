local ParentClass = require 'Lua.Parent'

local m = ParentClass:New({Super = Super})

function m:ReceiveBeginPlay()
    print('receive begin play in SubClass1')
    
    ParentClass.ReceiveBeginPlay(self)
end

return m