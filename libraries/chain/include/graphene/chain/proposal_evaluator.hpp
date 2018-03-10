/*
 * Copyright (c) 2015 Cryptonomex, Inc., and contributors.
 *
 * The MIT License
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#pragma once

#include <enudex/chain/protocol/operations.hpp>
#include <enudex/chain/evaluator.hpp>
#include <enudex/chain/database.hpp>
#include <enudex/chain/transaction_evaluation_state.hpp>

namespace enudex { namespace chain {

   class proposal_create_evaluator : public evaluator<proposal_create_evaluator>
   {
      public:
         typedef proposal_create_operation operation_type;

         void_result do_evaluate( const proposal_create_operation& o );
         object_id_type do_apply( const proposal_create_operation& o );

         transaction _proposed_trx;
   };

   class proposal_update_evaluator : public evaluator<proposal_update_evaluator>
   {
      public:
         typedef proposal_update_operation operation_type;

         void_result do_evaluate( const proposal_update_operation& o );
         void_result do_apply( const proposal_update_operation& o );

         const proposal_object* _proposal = nullptr;
         processed_transaction _processed_transaction;
         bool _executed_proposal = false;
         bool _proposal_failed = false;
   };

   class proposal_delete_evaluator : public evaluator<proposal_delete_evaluator>
   {
      public:
         typedef proposal_delete_operation operation_type;

         void_result do_evaluate( const proposal_delete_operation& o );
         void_result do_apply(const proposal_delete_operation&);

         const proposal_object* _proposal = nullptr;
   };

} } // enudex::chain
