using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;

namespace ApiSrcData
{
    public static class Helper
    {
        public static Dictionary<Type, List<FieldInfo>> GetResultStructs()
        {
            var enumNames = Enum.GetNames(typeof(RiotApiType.ApiType));

            var results = enumNames
                .Select(enumName =>
                    $"ApiSrcData.ResultStruct.{enumName}, ApiSrcData, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null")
                .Select(Type.GetType)
                .Where(resultType => resultType != null)
                .ToList();

            return GetAllMembers(results);
        }

        public static Dictionary<Type, List<FieldInfo>> GetInternalStructs()
        {
            var apiSrcDataAssem = Assembly.GetAssembly(typeof(RiotApiType.ApiType));

            var internals = GetTypesInNamespace(apiSrcDataAssem, "ApiSrcData.InternalStruct");

            return GetAllMembers(internals);
        }

        static List<Type> GetTypesInNamespace(Assembly assembly, string nameSpace)
        {
            return assembly.GetTypes()
                .Where(t => string.Equals(t.Namespace, nameSpace, StringComparison.Ordinal))
                .ToList();
        }

        public static string GetCppTypeName(Type type)
        {
            return IsGeneric(type)
                ? GetGenericCppTypeName(type)
                : GetRawCppTypeName(type);
        }

        public static bool IsGeneric(Type type)
        {
            return type.GenericTypeArguments.Length != 0;
        }

        public static bool IsList(Type type)
        {
            return type.GetGenericTypeDefinition() == typeof(List<>);
        }

        public static bool IsInternalStruct(Type type)
        {
            var internals = GetInternalStructs();
            return internals.ContainsKey(type);
        }

        static string GetRawCppTypeName(Type type)
        {
            var typeMap = new Dictionary<Type, string>
            {
                {typeof(bool), "bool"},
                {typeof(int), "int"},
                {typeof(long), "long"},
                {typeof(string), "std::string"}
            };

            typeMap.TryGetValue(type, out var ret);
            return ret ?? type.Name;
        }

        static string GetGenericCppTypeName(Type type)
        {
            if (IsList(type))
            {
                var valueType = type.GenericTypeArguments[0];
                return $"std::vector<{GetRawCppTypeName(valueType)}>";
            }
            else
            {
                return type.FullName;
            }
        }

        static Dictionary<Type, List<FieldInfo>> GetAllMembers(List<Type> classTypes)
        {
            var dict = new Dictionary<Type, List<FieldInfo>>();

            foreach (var classType in classTypes)
            {
                var members = new List<FieldInfo>();
                members.AddRange(classType.GetFields(BindingFlags.Instance |
                                                     BindingFlags.NonPublic |
                                                     BindingFlags.Public));

                dict.Add(classType, members);
            }

            return dict;
        }
    }
}