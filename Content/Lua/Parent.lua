local m = { Super = Super }

function m:New(obj)
    obj = obj or {}
    self.__index = self
    return setmetatable(obj, self)
end

function m:PrintSuper()
    print('Current Super is:', tostring(self.Super))
end

function m:ReceiveBeginPlay()
    print('receive begin play in Parent')
    self:PrintSuper()
end

return m