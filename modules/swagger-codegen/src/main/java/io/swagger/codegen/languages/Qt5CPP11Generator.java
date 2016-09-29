package io.swagger.codegen.languages;

import io.swagger.codegen.*;
import io.swagger.models.Model;
import io.swagger.models.Operation;
import io.swagger.models.Swagger;
import io.swagger.models.parameters.Parameter;
import io.swagger.models.properties.*;

import java.io.File;
import java.util.*;

public class Qt5CPP11Generator extends DefaultCodegen implements CodegenConfig {
    protected final String PREFIX = "SWG";

    public static final String GENERATE_QOBJECTS = "generateQObjects";

    protected Set<String> foundationClasses = new HashSet<String>();
    // source folder where to write the files
    protected String sourceFolder = "client";
    protected String apiVersion = "1.0.0";
    protected Map<String, String> namespaces = new HashMap<String, String>();
    protected Set<String> systemIncludes = new HashSet<String>();

    protected Set<String> copyableTypes = new HashSet<>();

    protected boolean generateQObjects = true;


    public Qt5CPP11Generator() {
        super();

        // set the output folder here
        outputFolder = "generated-code/qt5cpp11";

        /*
         * Models.  You can write model files using the modelTemplateFiles map.
         * if you want to create one template for file, you can do so here.
         * for multiple files for model, just put another entry in the `modelTemplateFiles` with
         * a different extension
         */
        modelTemplateFiles.put(
                "model-header.mustache",
                ".h");

        modelTemplateFiles.put(
                "model-body.mustache",
                ".cpp");

        /*
         * Api classes.  You can write classes for each Api file with the apiTemplateFiles map.
         * as with models, add multiple entries with different extensions for multiple files per
         * class
         */
        apiTemplateFiles.put(
                "api-header.mustache",   // the template to use
                ".h");       // the extension for each file to write

        apiTemplateFiles.put(
                "api-body.mustache",   // the template to use
                ".cpp");       // the extension for each file to write

        /*
         * Template Location.  This is the location which templates will be read from.  The generator
         * will use the resource stream to attempt to read the templates.
         */
        embeddedTemplateDir = templateDir = "qt5cpp11";

        /*
         * Reserved words.  Override this with reserved words specific to your language
         */
        setReservedWordsLowerCase(
                Arrays.asList(
                        "sample1",  // replace with static values
                        "sample2")
        );

        /*
         * Additional Properties.  These values can be passed to the templates and
         * are available in models, apis, and supporting files
         */
        additionalProperties.put("apiVersion", apiVersion);
        additionalProperties().put("prefix", PREFIX);

        /*
         * Language Specific Primitives.  These types will not trigger imports by
         * the client generator
         */
        languageSpecificPrimitives = new HashSet<String>(
                Arrays.asList(
                        "bool",
                        "qint32",
                        "qint64",
                        "float",
                        "double")
        );

        //supportingFiles.add(new SupportingFile("helpers-header.mustache", sourceFolder, PREFIX + "Helpers.h"));
        //supportingFiles.add(new SupportingFile("helpers-body.mustache", sourceFolder, PREFIX + "Helpers.cpp"));
        //supportingFiles.add(new SupportingFile("HttpRequest.h.mustache", sourceFolder, PREFIX + "HttpRequest.h"));
        //supportingFiles.add(new SupportingFile("HttpRequest.cpp.mustache", sourceFolder, PREFIX + "HttpRequest.cpp"));
        //supportingFiles.add(new SupportingFile("modelFactory.mustache", sourceFolder, PREFIX + "ModelFactory.h"));
        //supportingFiles.add(new SupportingFile("object.mustache", sourceFolder, PREFIX + "Object.h"));

        super.typeMapping = new HashMap<String, String>();

        typeMapping.put("date", "QDate");
        typeMapping.put("DateTime", "QDateTime");
        typeMapping.put("string", "QString");
        typeMapping.put("integer", "qint32");
        typeMapping.put("long", "qint64");
        typeMapping.put("boolean", "bool");
        typeMapping.put("array", "QList");
        typeMapping.put("map", "QMap");
        typeMapping.put("file", "QIODevice");
        typeMapping.put("object", PREFIX + "Object");
        //TODO binary should be mapped to byte array
        // mapped to String as a workaround
        typeMapping.put("binary", "QString");
        typeMapping.put("ByteArray", "QByteArray");

        copyableTypes.add("QDate");
        copyableTypes.add("QDateTime");
        copyableTypes.add("QString");
        copyableTypes.add("qint32");
        copyableTypes.add("qint64");
        copyableTypes.add("bool");
        copyableTypes.add("QList");
        copyableTypes.add("QMap");
        copyableTypes.add("QByteArray");

        additionalProperties.put("copyables", copyableTypes);

        importMapping = new HashMap<String, String>();

        //importMapping.put("SWGHttpRequestInputFileElement", "#include \"" + PREFIX + "HttpRequest.h\"");

        namespaces = new HashMap<String, String>();

        foundationClasses.add("QString");
        foundationClasses.add("QIODevice");

        systemIncludes.add("QString");
        systemIncludes.add("QList");
        systemIncludes.add("QMap");
        systemIncludes.add("QDate");
        systemIncludes.add("QDateTime");
        systemIncludes.add("QByteArray");

        // Prepare commandline parameters
        cliOptions.add(new CliOption(GENERATE_QOBJECTS, "Generate QObject-derived classes").
                defaultValue(Boolean.TRUE.toString()));
    }

    @Override
    public void processOpts() {
        super.processOpts();

        if (additionalProperties.containsKey(GENERATE_QOBJECTS)) {
            generateQObjects = Boolean.valueOf(additionalProperties.get(GENERATE_QOBJECTS).toString());

            additionalProperties.put("generateQObjects", generateQObjects);
        }
    }

    /**
     * Configures the type of generator.
     *
     * @return the CodegenType for this generator
     * @see CodegenType
     */
    @Override
    public CodegenType getTag() {
        return CodegenType.CLIENT;
    }

    /**
     * Configures a friendly name for the generator.  This will be used by the generator
     * to select the library with the -l flag.
     *
     * @return the friendly name for the generator
     */
    @Override
    public String getName() {
        return "qt5cpp11";
    }

    /**
     * Returns human-friendly help for the generator.  Provide the consumer with help
     * tips, parameters here
     *
     * @return A string value for the help message
     */
    @Override
    public String getHelp() {
        return "Generates a qt5 C++ client library.";
    }

    @Override
    public String toModelImport(String name) {
        if (namespaces.containsKey(name)) {
            return "using " + namespaces.get(name) + ";";
        } else if (systemIncludes.contains(name)) {
            return "#include <" + name + ">";
        }
        return "#include \"" + name + ".h\"";
    }

    private String getToJsonFunction(Property p) {
        String conversionFunction = null;

        if (p instanceof DateProperty) {
            conversionFunction = ".toString(Qt::ISODate)";
        } else if (p instanceof DateTimeProperty) {
            conversionFunction = ".toString(Qt::ISODate)";
        }

        return conversionFunction;
    }

    private String getFromJsonFunction(Property p) {
        String conversionFunction = null;

        if (p instanceof StringProperty) {
            conversionFunction = "toString";
        } else if (p instanceof BooleanProperty) {
            conversionFunction = "toBool";
        } else if (p instanceof DateProperty) {
            conversionFunction = "toDateTime";
        } else if (p instanceof DateTimeProperty) {
            conversionFunction = "toDateTime";
        } else if (p instanceof DoubleProperty) {
            conversionFunction = "toNumber";
        } else if (p instanceof FloatProperty) {
            conversionFunction = "toNumber";
        } else if (p instanceof IntegerProperty) {
            conversionFunction = "toInt";
        } else if (p instanceof LongProperty) {
            conversionFunction = "toInt";
        } else if (p instanceof BaseIntegerProperty) {
            // catchall for any other format of the swagger specifiction
            // integer type not explicitly handled above
            conversionFunction = "toInt";
        } else if (p instanceof DecimalProperty) {
            conversionFunction = "toNumber";
        } else if (p instanceof MapProperty) {
            conversionFunction = "toObject";
        } else if (p instanceof ArrayProperty) {
            conversionFunction = "toArray";
        }

        return conversionFunction;
    }

    @Override
    public CodegenOperation fromOperation(String path, String httpMethod, Operation operation, Map<String, Model> definitions, Swagger swagger) {
        CodegenOperation op = super.fromOperation(path, httpMethod, operation, definitions, swagger);

        if (op.returnBaseType != null && !copyableTypes.contains(op.returnBaseType)) {
            op.vendorExtensions.put("x-codegen-isPointer", true);
        }

        // Add x-codgen-hasFiles property if we have at least one file parameter
        if (op.getHasFormParams()) {
            for(CodegenParameter parameter : op.formParams) {
                if (Boolean.TRUE.equals(parameter.isFile)) {
                    op.vendorExtensions.put("x-codegen-hasFiles", true);
                    break;
                }
            }
        }

        op.vendorExtensions.put("x-codegen-http-" + httpMethod.toLowerCase(), true);

        return op;
    }

    @Override
    public CodegenParameter fromParameter(Parameter param, Set<String> imports) {
        CodegenParameter p = super.fromParameter(param, imports);

        if (p.baseType != null && !copyableTypes.contains(p.baseType)) {
            if (Boolean.TRUE.equals(p.isContainer)) {
                p.vendorExtensions.put("x-codegen-inner-isPointer", true);
            } else {
                p.vendorExtensions.put("x-codegen-isPointer", true);
            }
        }

        return p;
    }

    @Override
    public CodegenProperty fromProperty(String name, Property p) {
        CodegenProperty property = super.fromProperty(name, p);
        property.getter = name; // Qt getters are not get-prefixed

        String type = getSwaggerType(p);

        if (!copyableTypes.contains(type)) {
            property.vendorExtensions.put("x-codegen-isPointer", true);
        } else {
            String fromJsonFunction = getFromJsonFunction(p);
            if (fromJsonFunction != null) {
                property.vendorExtensions.put("x-codegen-fromJsonFunction", fromJsonFunction);
            }

            String toJsonFunction = getToJsonFunction(p);
            if (toJsonFunction != null) {
                property.vendorExtensions.put("x-codegen-toJsonFunction", toJsonFunction);
            }
        }

        if (p instanceof ArrayProperty) {
            ArrayProperty ap = (ArrayProperty) p;
            Property inner = ap.getItems();

            if (!copyableTypes.contains(getSwaggerType(inner))) {
                property.vendorExtensions.put("x-codegen-inner-isPointer", true);
            } else {
                String fromJsonFunction = getFromJsonFunction(inner);
                if (fromJsonFunction != null) {
                    property.vendorExtensions.put("x-codegen-inner-fromJsonFunction", fromJsonFunction);
                }

                String toJsonFunction = getToJsonFunction(inner);
                if (toJsonFunction != null) {
                    property.vendorExtensions.put("x-codegen-inner-toJsonFunction", toJsonFunction);
                }
            }
        }

        return property;
    }

    /**
     * Escapes a reserved word as defined in the `reservedWords` array. Handle escaping
     * those terms here.  This logic is only called if a variable matches the reseved words
     *
     * @return the escaped term
     */
    @Override
    public String escapeReservedWord(String name) {
        return "_" + name;  // add an underscore to the name
    }

    /**
     * Location to write model files.  You can use the modelPackage() as defined when the class is
     * instantiated
     */
    @Override
    public String modelFileFolder() {
        return outputFolder + "/" + sourceFolder + "/" + modelPackage().replace('.', File.separatorChar);
    }

    /**
     * Location to write api files.  You can use the apiPackage() as defined when the class is
     * instantiated
     */
    @Override
    public String apiFileFolder() {
        return outputFolder + "/" + sourceFolder + "/" + apiPackage().replace('.', File.separatorChar);
    }

    @Override
    public String toModelFilename(String name) {
        return PREFIX + initialCaps(name);
    }

    @Override
    public String toApiFilename(String name) {
        return PREFIX + initialCaps(name) + "Api";
    }

    /**
     * Optional - type declaration.  This is a String which is used by the templates to instantiate your
     * types.  There is typically special handling for different property types
     *
     * @return a string value used as the `dataType` field for model templates, `returnType` for api templates
     */
    @Override
    public String getTypeDeclaration(Property p) {
        String swaggerType = getSwaggerType(p);

        if (p instanceof ArrayProperty) {
            ArrayProperty ap = (ArrayProperty) p;
            Property inner = ap.getItems();
            return "const " + getSwaggerType(p) + "<" + getInnerTypeDeclaration(inner) + ">&";
        } else if (p instanceof MapProperty) {
            MapProperty mp = (MapProperty) p;
            Property inner = mp.getAdditionalProperties();
            return "const " + getSwaggerType(p) + "<QString, " + getInnerTypeDeclaration(inner) + ">&";
        }
        if (copyableTypes.contains(swaggerType)) {
            return "const " +  swaggerType + "&";
        } else if (foundationClasses.contains(swaggerType)) {
            return swaggerType + "*";
        } else if (languageSpecificPrimitives.contains(swaggerType)) {
            return toModelName(swaggerType);
        } else {
            return swaggerType + "*";
        }
    }

    private String getInnerTypeDeclaration(Property p) {
        String swaggerType = getSwaggerType(p);

        if (p instanceof ArrayProperty) {
            ArrayProperty ap = (ArrayProperty) p;
            Property inner = ap.getItems();
            return getSwaggerType(p) + "<" + getTypeDeclaration(inner) + ">";
        } else if (p instanceof MapProperty) {
            MapProperty mp = (MapProperty) p;
            Property inner = mp.getAdditionalProperties();
            return getSwaggerType(p) + "<QString, " + getTypeDeclaration(inner) + ">";
        }
        if (copyableTypes.contains(swaggerType)) {
            return swaggerType;
        } else if (foundationClasses.contains(swaggerType)) {
            return swaggerType + " *****";
        } else if (languageSpecificPrimitives.contains(swaggerType)) {
            return toModelName(swaggerType);
        } else {
            return swaggerType + "*";
        }
    }

    @Override
    public String toDefaultValue(Property p) {
        if (p instanceof StringProperty) {
            return null;
        } else if (p instanceof BooleanProperty) {
            return "false";
        } else if (p instanceof DateProperty) {
            return null;
        } else if (p instanceof DateTimeProperty) {
            return null;
        } else if (p instanceof DoubleProperty) {
            return "0.0";
        } else if (p instanceof FloatProperty) {
            return "0.0f";
        } else if (p instanceof IntegerProperty) {
            return "0";
        } else if (p instanceof LongProperty) {
            return "0L";
        } else if (p instanceof BaseIntegerProperty) {
            // catchall for any other format of the swagger specifiction
            // integer type not explicitly handled above
            return "0";
        } else if (p instanceof DecimalProperty) {
            return "0.0";
        } else if (p instanceof MapProperty) {
            return null;
        } else if (p instanceof ArrayProperty) {
            return null;
        }
        // else

        /*
        if (p instanceof RefProperty) {
            RefProperty rp = (RefProperty) p;
            return "new " + toModelName(rp.getSimpleRef()) + "()";
        }
        */

        return "nullptr";
    }


    /**
     * Optional - swagger type conversion.  This is used to map swagger types in a `Property` into
     * either language specific types via `typeMapping` or into complex models if there is not a mapping.
     *
     * @return a string value of the type or complex model for this property
     * @see Property
     */
    @Override
    public String getSwaggerType(Property p) {
        String swaggerType = super.getSwaggerType(p);
        String type = null;
        if (typeMapping.containsKey(swaggerType)) {
            type = typeMapping.get(swaggerType);
            if (languageSpecificPrimitives.contains(type)) {
                return toModelName(type);
            }
            if (foundationClasses.contains(type)) {
                return type;
            }
        } else {
            type = swaggerType;
        }
        return toModelName(type);
    }

    @Override
    public String toModelName(String type) {
        if (typeMapping.keySet().contains(type) ||
                typeMapping.values().contains(type) ||
                importMapping.values().contains(type) ||
                defaultIncludes.contains(type) ||
                languageSpecificPrimitives.contains(type)) {
            return type;
        } else {
            return PREFIX + Character.toUpperCase(type.charAt(0)) + type.substring(1);

        }
    }

    @Override
    public String toApiName(String type) {
        return PREFIX + Character.toUpperCase(type.charAt(0)) + type.substring(1) + "Api";
    }

    @Override
    public String escapeQuotationMark(String input) {
        // remove " to avoid code injection
        return input.replace("\"", "");
    }

    @Override
    public String escapeUnsafeCharacters(String input) {
        return input.replace("*/", "*_/").replace("/*", "/_*");
    }
}
