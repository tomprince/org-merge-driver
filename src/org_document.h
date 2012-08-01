/**
 * @file org_document.h
 */
#ifndef ORG_DOCUMENT_H
#define ORG_DOCUMENT_H

#include "doc_stream.h"
#include "doc_ref.h"

/* type forward declaration */
struct org_document;
typedef struct org_document org_document;

typedef struct org_heading org_heading;
typedef struct org_text org_text;
typedef struct print_ctxt print_ctxt;

/* shov the ops */
typedef struct doc_elt_ops doc_elt_ops;
extern doc_elt_ops org_document_ops;

/* Constructor, Destructor */
org_document *org_document_create_empty (doc_elt_ops *org_doc_ops);
void org_document_free (org_document *self);

/* Adding sub elements */
void org_document_add_text_last (org_document *document, doc_src src, org_text *text);
void org_document_add_heading_last (org_document *document, doc_src src, org_heading *text);

void org_document_print (org_document *doc, print_ctxt *ctxt, doc_stream *out);
void org_document_merge (org_document *anc, org_document *desc);

#endif /* ORG_DOCUMENT_H */